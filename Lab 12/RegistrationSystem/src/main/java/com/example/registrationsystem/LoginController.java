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

public class LoginController {

    @FXML
    private BorderPane loginPane;

    @FXML
    private TextField usernameField;

    @FXML
    private PasswordField passwordField;

    @FXML
    protected void handleLogin(ActionEvent event) {
        String username = usernameField.getText();
        String password = passwordField.getText();

        // Dummy validation logic
        if (username.equals("user") && password.equals("pass")) {
            System.out.println("Login successful!");
        } else {
            System.out.println("Invalid credentials");
        }
    }

    @FXML
    protected void switchToRegister(ActionEvent event) {
        // Print the value of loginPane
        System.out.println("Login Pane: " + loginPane);

        try {
            Parent registerView = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("register.fxml")));
            Scene registerScene = new Scene(registerView);
            Stage window = (Stage) loginPane.getScene().getWindow();
            window.setScene(registerScene);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
