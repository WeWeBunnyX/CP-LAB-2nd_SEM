import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.List;

public class StudentRegistrationController {
    @FXML
    private TextField nameField;

    @FXML
    private TextField idField;

    @FXML
    private TextField emailField;

    @FXML
    private ListView<String> courseListView;

    private final ObservableList<String> selectedCourses = FXCollections.observableArrayList();

    public void initialize() {
        // Initialize course list view with some sample courses
        List<String> sampleCourses = List.of("Mathematics", "Physics", "Chemistry", "Computer Science");
        courseListView.setItems(FXCollections.observableArrayList(sampleCourses));
        courseListView.getSelectionModel().selectedItemProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null) {
                selectedCourses.add(newValue);
            }
        });
    }

    @FXML
    private void register(ActionEvent event) {
        String name = nameField.getText();
        String id = idField.getText();
        String email = emailField.getText();

        // Save student details to a file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("student_details.txt"))) {
            writer.write("Name: " + name + "\n");
            writer.write("ID: " + id + "\n");
            writer.write("Email: " + email + "\n");

            writer.write("Selected Courses:\n");
            for (String course : selectedCourses) {
                writer.write(course + "\n");
            }

            System.out.println("Registration successful. Details saved to student_details.txt");
        } catch (IOException e) {
            System.err.println("Error occurred while saving student details: " + e.getMessage());
        }
    }
}
