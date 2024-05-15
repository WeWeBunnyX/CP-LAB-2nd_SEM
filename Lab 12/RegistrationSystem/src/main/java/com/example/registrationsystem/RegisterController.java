package com.example.registrationsystem;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Objects;

public class RegisterController {

    @FXML
    private BorderPane registerPane;

    @FXML
    private TextField usernameField;

    @FXML
    private PasswordField passwordField;

    @FXML
    private PasswordField confirmPasswordField;

    @FXML
    protected void handleRegister(ActionEvent event) {
        String username = usernameField.getText();
        String password = passwordField.getText();
        String confirmPassword = confirmPasswordField.getText();

        if (username.isEmpty() || password.isEmpty()) {
            System.out.println("Username and Password cannot be empty");
        } else if (!password.equals(confirmPassword)) {
            System.out.println("Passwords do not match");
        } else {
            System.out.println("Registration successful!");
        }
    }


    @FXML
    protected void switchToLogin(ActionEvent event) {
        try {
            Parent loginView = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("login.fxml")));
            Scene loginScene = new Scene(loginView);
            Stage window = (Stage) registerPane.getScene().getWindow();
            window.setScene(loginScene);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
