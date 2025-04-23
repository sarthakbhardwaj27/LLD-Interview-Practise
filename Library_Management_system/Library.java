import java.util.ArrayList;

public class Library {
    private String name;
    private String address;
    private ArrayList<Item> allItems;

    public Library(String name, String address) {
        this.name = name;
        this.address = address;
        this.allItems = new ArrayList<>();
    }

    public void addItem(Item item) {
        allItems.add(item);
    }

    public int getValue() {
        int total = 0;
        for (Item item : allItems) {
            total += item.getPrice();
        }
        return total;
    }

    public int getTotalLateFees() {
        int totalFees = 0;
        for (Item item : allItems) {
            totalFees += item.getLateFees();
        }
        return totalFees;
    }
}
