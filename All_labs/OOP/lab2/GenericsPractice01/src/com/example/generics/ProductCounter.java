package Labs.All_labs.OOP.lab2.GenericsPractice01.src.com.example.generics;

import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class ProductCounter {
    private Map<String, Long> productCountMap = new HashMap<>();
    private Map<String, String> productNames;

    public static void main(String[] args) {
        // List of part data
        String[] parts = new String[]{
            "1S01", "1S01", "1S01", "1S01", "1S01",
            "1S02", "1S02", "1S02", "1H01", "1H01",
            "1S02", "1S01", "1S01", "1H01", "1H01",
            "1H01", "1S02", "1S02", "1M02", "1M02", "1M02"
        };

        // Create Product Name Part Number map
        Map<String, String> productNames = new TreeMap<>();
        productNames.put("1S01", "Blue Polo Shirt");
        productNames.put("1S02", "Black Polo Shirt");
        productNames.put("1H01", "Red Ball Cap");
        productNames.put("1M02", "Duke Mug");

        // Create Product Counter Object and process data
        ProductCounter pc1 = new ProductCounter(productNames);
        pc1.processList(parts);
        pc1.printReport();
    }

    public ProductCounter(Map<String, String> productNames) {
        this.productNames = productNames;
    }

    public void processList(String[] list) {
        for (String itemNumber : list) {
            productCountMap.put(itemNumber, productCountMap.getOrDefault(itemNumber, 0L) + 1);
        }
    }

    public void printReport() {
        System.out.println("=== Product Report ===");
        for (String key : productCountMap.keySet()) {
            String name = productNames.getOrDefault(key, "Unknown Product");
            System.out.println("Name: " + name);
            System.out.println("\t\tCount: " + productCountMap.get(key));
        }
    }
}
