public abstract class Item {
    private String name;
    private int ID;
    private int price;
    private int lateFees;

    public Item(String name, int ID, int price, int lateFees) {
        this.name = name;
        this.ID = ID;
        this.price = price;
        this.lateFees = lateFees;
    }

    public int getPrice() {
        return price;
    }

    public int getLateFees() {
        return lateFees;
    }

    public int getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public abstract String getItemCategory();
}
