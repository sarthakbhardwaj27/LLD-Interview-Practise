public class Main {
    public static void main(String[] args) {
        Library l1 = new Library("Children's Library", "Bangalore");

        Book book1 = new Book("CDCI", 1, 500, 100, "Sarthak");
        l1.addItem(book1);

        System.out.println("Total value of library: " + l1.getValue());
        System.out.println("Total late fees: " + l1.getTotalLateFees());
    }
}


