-- Create database if not exists
CREATE DATABASE IF NOT EXISTS regdb;

-- Use the regdb database
USE regdb;

-- Create the products table
CREATE TABLE IF NOT EXISTS products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    price DECIMAL(10, 2) NOT NULL DEFAULT 0.00,
    quantity INT NOT NULL DEFAULT 0
);


INSERT INTO products (name, price, quantity) VALUES
    ('Drink', 2.99, 50),
    ('Oil', 6.49, 30),
    ('Brush', 4.99, 20);
