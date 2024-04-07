package application;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class AddressBook extends Application {

    private final ObservableList<Contact> contacts = FXCollections.observableArrayList(); // Observable list for contacts
    private final TableView<Contact> tableView = new TableView<>(); // TableView for displaying contacts
    private final TextField nameField = new TextField();
    private final TextField phoneField = new TextField();
    private final TextField emailField = new TextField();

    @Override
    public void start(Stage primaryStage) {
        // Create UI components
        Label nameLabel = new Label("Name:");
        Label phoneLabel = new Label("Phone Number:");
        Label emailLabel = new Label("Email:");

        // Initialize columns for TableView
        TableColumn<Contact, String> nameColumn = new TableColumn<>("Name");
        nameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));

        TableColumn<Contact, String> phoneColumn = new TableColumn<>("Phone Number");
        phoneColumn.setCellValueFactory(new PropertyValueFactory<>("phoneNumber"));

        TableColumn<Contact, String> emailColumn = new TableColumn<>("Email");
        emailColumn.setCellValueFactory(new PropertyValueFactory<>("email"));

        // Add columns to TableView
        tableView.getColumns().addAll(nameColumn, phoneColumn, emailColumn);
        tableView.setItems(contacts);

        // Set selection listener for TableView
        tableView.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
            if (newSelection != null) {
                // Populate text fields with selected contact details
                nameField.setText(newSelection.getName());
                phoneField.setText(newSelection.getPhoneNumber());
                emailField.setText(newSelection.getEmail());
            }
        });

        // Buttons for adding, editing, and deleting contacts
        Button addButton = new Button("Add Contact");
        addButton.setOnAction(e -> addContact());

        Button editButton = new Button("Edit Contact");
        editButton.setOnAction(e -> editContact());

        Button deleteButton = new Button("Delete Contact");
        deleteButton.setOnAction(e -> deleteContact());

        // Create layout
        VBox formLayout = new VBox(10);
        formLayout.getChildren().addAll(nameLabel, nameField, phoneLabel, phoneField,
                emailLabel, emailField, addButton, editButton, deleteButton);

        VBox root = new VBox(20);
        root.getChildren().addAll(formLayout, tableView);

        // Create scene and set on stage
        Scene scene = new Scene(root, 600, 400);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Address Book");
        primaryStage.show();
    }

    // Method to add a new contact
    private void addContact() {
        String name = nameField.getText();
        String phoneNumber = phoneField.getText();
        String email = emailField.getText();

        if (!name.isEmpty() && !phoneNumber.isEmpty() && !email.isEmpty()) {
            contacts.add(new Contact(name, phoneNumber, email));
            clearFields();
        } else {
            showAlert("Please enter name, phone number, and email.");
        }
    }

    // Method to edit an existing contact
    private void editContact() {
        Contact selectedContact = tableView.getSelectionModel().getSelectedItem();
        if (selectedContact != null) {
            String name = nameField.getText();
            String phoneNumber = phoneField.getText();
            String email = emailField.getText();

            if (!name.isEmpty() && !phoneNumber.isEmpty() && !email.isEmpty()) {
                selectedContact.setName(name);
                selectedContact.setPhoneNumber(phoneNumber);
                selectedContact.setEmail(email);
                tableView.refresh();
                clearFields();
            } else {
                showAlert("Please enter name, phone number, and email.");
            }
        } else {
            showAlert("Please select a contact to edit.");
        }
    }

    // Method to delete a contact
    private void deleteContact() {
        int selectedIndex = tableView.getSelectionModel().getSelectedIndex();
        if (selectedIndex >= 0) {
            tableView.getItems().remove(selectedIndex);
            clearFields();
        } else {
            showAlert("Please select a contact to delete.");
        }
    }

    // Method to clear text fields
    private void clearFields() {
        nameField.clear();
        phoneField.clear();
        emailField.clear();
    }

    // Method to show an alert dialog
    private void showAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.WARNING);
        alert.setTitle("Warning");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

class Contact {
    private String name;
    private String phoneNumber;
    private String email;

    public Contact(String name, String phoneNumber, String email) {
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
