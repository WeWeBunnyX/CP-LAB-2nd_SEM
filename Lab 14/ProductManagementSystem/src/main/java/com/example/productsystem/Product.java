package com.example.productsystem;

public class Product {
    private int id;
    private final String name;
    private final double price;
    private final int quantity; // Add quantity field

    public Product(int id, String name, double price, int quantity) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.quantity = quantity; // Initialize quantity
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public int getQuantity() {
        return quantity; // Return quantity
    }
}
