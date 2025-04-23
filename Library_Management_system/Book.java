public class Book extends Item {
    private String author;

    public Book(String name, int ID, int price, int lateFees, String author) {
        super(name, ID, price, lateFees);
        this.author = author;
    }

    @Override
    public String getItemCategory() {
        return "Book";
    }

    public String getAuthor() {
        return author;
    }
}
