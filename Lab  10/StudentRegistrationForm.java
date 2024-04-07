package application;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class StudentRegistrationForm extends Application {

    private final ObservableList<Student> students = FXCollections.observableArrayList(); 

    @Override
    public void start(Stage primaryStage) {

        Label nameLabel = new Label("Name:");
        TextField nameField = new TextField();

        Label idLabel = new Label("ID:");
        TextField idField = new TextField();

        Label emailLabel = new Label("Email:");
        TextField emailField = new TextField();

        Label genderLabel = new Label("Gender:");
        ToggleGroup genderGroup = new ToggleGroup();
        RadioButton maleRadioButton = new RadioButton("Male");
        maleRadioButton.setToggleGroup(genderGroup);
        RadioButton femaleRadioButton = new RadioButton("Female");
        femaleRadioButton.setToggleGroup(genderGroup);

        CheckBox termsCheckbox = new CheckBox("I agree to the terms and conditions");

        TableView<Student> tableView = new TableView<>();

        TableColumn<Student, String> nameColumn = new TableColumn<>("Name");
        nameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));

        TableColumn<Student, String> idColumn = new TableColumn<>("ID");
        idColumn.setCellValueFactory(new PropertyValueFactory<>("id"));

        TableColumn<Student, String> emailColumn = new TableColumn<>("Email");
        emailColumn.setCellValueFactory(new PropertyValueFactory<>("email"));

        TableColumn<Student, String> genderColumn = new TableColumn<>("Gender");
        genderColumn.setCellValueFactory(new PropertyValueFactory<>("gender"));

        TableColumn<Student, Boolean> termsColumn = new TableColumn<>("Agreed to Terms");
        termsColumn.setCellValueFactory(new PropertyValueFactory<>("agreedToTerms"));

        tableView.getColumns().addAll(nameColumn, idColumn, emailColumn, genderColumn, termsColumn);
        tableView.setItems(students); 

        Button submitButton = new Button("Submit");
        submitButton.setOnAction(e -> {
            
            String name = nameField.getText();
            int id = Integer.parseInt(idField.getText()); 
            String email = emailField.getText();
            String gender = maleRadioButton.isSelected() ? "Male" : "Female";
            boolean agreedToTerms = termsCheckbox.isSelected();

            
            Student student = new Student(name, id, email, gender, agreedToTerms);
            students.add(student);

            nameField.clear();
            idField.clear();
            emailField.clear();
            genderGroup.selectToggle(null);
            termsCheckbox.setSelected(false);
        });
        VBox formLayout = new VBox(10);
        formLayout.getChildren().addAll(nameLabel, nameField, idLabel, idField,
                emailLabel, emailField, genderLabel, maleRadioButton, femaleRadioButton,
                termsCheckbox, submitButton);

        VBox root = new VBox(20);
        root.getChildren().addAll(formLayout, tableView);

        Scene scene = new Scene(root, 600, 400);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Student Registration Form");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

class Student {
    private String name;
    private int id; 
    private String email;
    private String gender;
    private boolean agreedToTerms;

    public Student(String name, int id, String email, String gender, boolean agreedToTerms) {
        this.name = name;
        this.id = id;
        this.email = email;
        this.gender = gender;
        this.agreedToTerms = agreedToTerms;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public String getEmail() {
        return email;
    }

    public String getGender() {
        return gender;
    }

    public boolean isAgreedToTerms() {
        return agreedToTerms;
    }
}
