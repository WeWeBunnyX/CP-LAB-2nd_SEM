module com.example.registrationsystem {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens com.example.productsystem to javafx.fxml;
    exports com.example.productsystem;
}