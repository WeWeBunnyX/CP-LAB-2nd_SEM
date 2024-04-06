import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;
import java.util.InputMismatchException;

public class BookInventorySystem {
    private ArrayList<Book> inventory;

    public BookInventorySystem() {
        inventory = new ArrayList<>();
    }

    public void addBook(Book book) {
        inventory.add(book);
    }

    public void removeBook(String title) {
        Iterator<Book> iterator = inventory.iterator();
        boolean bookFound = false;
        while (iterator.hasNext()) {
            Book book = iterator.next();
            if (book.getTitle().equals(title)) {
                iterator.remove();
                bookFound = true;
                break;
            }
        }
        if (!bookFound) {
            System.out.println("Book with title '" + title + "' does not exist in the inventory.");
        }
    }

    public void displayInventory() {
        System.out.println("Inventory:");
        for (Book book : inventory) {
            System.out.println(book);
        }
    }

    public static void main(String[] args) {
        BookInventorySystem bookSystem = new BookInventorySystem();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Add a book");
            System.out.println("2. Remove a book");
            System.out.println("3. Display inventory");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            try {
                choice = scanner.nextInt();
                scanner.nextLine(); // Consume newline character

                switch (choice) {
                    case 1:
                        addBookOption(bookSystem, scanner);
                        break;
                    case 2:
                        removeBookOption(bookSystem, scanner);
                        break;
                    case 3:
                        bookSystem.displayInventory();
                        break;
                    case 4:
                        System.out.println("Exiting...");
                        break;
                    default:
                        System.out.println("Invalid choice. Please try again.");
                }
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a number.");
                scanner.nextLine(); // Consume invalid input
                choice = 0;
            }
        } while (choice != 4);

        scanner.close();
    }

    private static void addBookOption(BookInventorySystem bookSystem, Scanner scanner) {
        System.out.print("Enter book title: ");
        String title = scanner.nextLine();
        System.out.print("Enter book author: ");
        String author = scanner.nextLine();
        double price;
        while (true) {
            try {
                System.out.print("Enter book price: ");
                price = scanner.nextDouble();
                scanner.nextLine(); // Consume newline character
                break;
            } catch (InputMismatchException e) {
                System.out.println("Invalid input. Please enter a valid price:");
                scanner.nextLine(); // Consume invalid input
            }
        }
        System.out.print("Enter book quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine(); // Consume newline character
        bookSystem.addBook(new Book(title, author, price, quantity));
        System.out.println("Book added successfully.");
    }

    private static void removeBookOption(BookInventorySystem bookSystem, Scanner scanner) {
        System.out.print("Enter title of the book to remove: ");
        String removeTitle = scanner.nextLine();
        bookSystem.removeBook(removeTitle);
    }
}

class Book {
    private String title;
    private String author;
    private double price;
    private int quantity;

    public Book(String title, String author, double price, int quantity) {
        this.title = title;
        this.author = author;
        this.price = price;
        this.quantity = quantity;
    }

    public String getTitle() {
        return title;
    }

    @Override
    public String toString() {
        return "Title: " + title + ", Author: " + author + ", Price: $" + price + ", Quantity: " + quantity;
    }
}
