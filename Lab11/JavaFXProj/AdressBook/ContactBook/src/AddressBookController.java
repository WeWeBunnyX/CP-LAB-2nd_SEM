import javafx.fxml.FXML;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;

public class AddressBookController {
    @FXML
    private TextField nameField;
    @FXML
    private TextField phoneField;
    @FXML
    private TextField emailField;
    @FXML
    private TableView<Contact> contactTable;

    @FXML
    private void addContact() {
        String name = nameField.getText();
        String phone = phoneField.getText();
        String email = emailField.getText();

        Contact newContact = new Contact(name, phone, email);
        contactTable.getItems().add(newContact);

        clearFields();
    }

    @FXML
    private void editContact() {
        Contact selectedContact = contactTable.getSelectionModel().getSelectedItem();
        if (selectedContact != null) {
            String name = nameField.getText();
            String phone = phoneField.getText();
            String email = emailField.getText();

            selectedContact.setName(name);
            selectedContact.setPhone(phone);
            selectedContact.setEmail(email);

            contactTable.refresh();
        }
    }

    @FXML
    private void deleteContact() {
        Contact selectedContact = contactTable.getSelectionModel().getSelectedItem();
        if (selectedContact != null) {
            contactTable.getItems().remove(selectedContact);
            clearFields();
        }
    }

    private void clearFields() {
        nameField.clear();
        phoneField.clear();
        emailField.clear();
    }
}
