module com.example.registrationsystem {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.registrationsystem to javafx.fxml;
    exports com.example.registrationsystem;
}