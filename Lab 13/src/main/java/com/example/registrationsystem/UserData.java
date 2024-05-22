package com.example.registrationsystem;

import java.util.HashMap;
import java.util.Map;

public class UserData {
    private static Map<String, String> users = new HashMap<>();

    public static void addUser(String username, String password) {
        users.put(username, password);
    }

    public static String getPassword(String username) {
        return users.get(username);
    }

    public static boolean userExists(String username) {
        return users.containsKey(username);
    }

    public static boolean registerUser(String username, String password) {
        if (userExists(username)) {
            return false; // User already exists
        } else {
            addUser(username, password);
            return true; // Registration successful
        }
    }
}
