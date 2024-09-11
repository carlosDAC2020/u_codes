/*
Estudiante
 - Carlos Daniel Agamez Palomino T00059006

    Reto: Simulador de Ventas

    Descripción: 
    Crea un programa en Java que simule un sistema de ventas para una tienda. El programa debe permitir al usuario ingresar el nombre de un producto, su precio y la cantidad vendida. Luego, debe calcular e imprimir el total de ventas, incluyendo impuestos.


    Requisitos:

        1 Utiliza una clase para modelar un producto, incluyendo atributos para el nombre, precio y cantidad vendida.

        2 Implementa una clase Venta que calcule el total de ventas, incluyendo un impuesto del 15%.

        3 Maneja diferentes rangos de precios para aplicar descuentos:

            - Si el precio del producto es menor a $100, aplica un descuento del 5%.

            - Si el precio del producto está entre $100 y $500, no aplica descuento.

            - Si el precio del producto es mayor a $500, aplica un descuento del 10%.

        4 Utiliza estructuras de control (if-else o switch) para aplicar los descuentos en función del rango de precios.

        5 Muestra mensajes claros al usuario durante la interacción con el programa.

*/

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Manejador de entradas desde teclado
    public static Scanner input = new Scanner(System.in);

    // Lista para almacenar ventas
    public static List<Sale> salesList = new ArrayList<>();

    // Clase Producto
    public static class Product {
        private String name;
        private double price;
        private String type; 
        private int quantityEntero;
        private double quantityPesado;
        private double total;
        private float discount;

        public Product(String name, double price, String type) {
            this.name = name;
            this.price = price;
            this.type = type;
            this.discount = 0;
            
        }

        public void setQuantity() {
            if (type.equalsIgnoreCase("entero")) {
                this.quantityEntero = GetInputInt("Cantidad (Unidades)");
            } else if (type.equalsIgnoreCase("pesado")) {
                this.quantityPesado = GetInputDouble("Cantidad (kg o g)");
            }
            this.total = this.TotalPrice();
        }

        public double TotalPrice() {
            double total;
            if (type.equalsIgnoreCase("entero")) {
                total = price * quantityEntero;
            } else {
                total = price * quantityPesado;
            }

            // Aplicar descuentos según el precio del producto
            if (price < 100) {
                total *= 0.95; // 5% de descuento
                this.discount = 5;
            } else if (price > 500) {
                total *= 0.90; // 10% de descuento
                this.discount = 10;
            }

            return total;
        }

        @Override
        public String toString() {
            return  "-------------------\n"+
                    " Nombre: " + name +"\n"+
                    " Precio: " + price +"$"+"\n"+
                    " Tipo: " + type +"\n"+
                    (type.equalsIgnoreCase("entero") ? " Cantidad: " + quantityEntero : " Cantidad: " + quantityPesado + "(kg o g)")+"\n"+
                    ((discount==0) ? " Descuento: No aplicado":" Descuento: "+discount+"%")+"\n"+
                    " total: "+total+"\n";
        }
    }

    
    // Clase Venta que maneja múltiples productos
    public static class Sale {
        private int id;
        private List<Product> products;
        private double total;

        public Sale(List<Product> products) {
            this.id = salesList.size() + 1; 
            this.products = products;
            calculateTotalWithTax();
        }

        private void calculateTotalWithTax() {
            double total = 0.0;
            for (Product product : products) {
                // se le va sumando el impuesto de 15 % a cada producto 
                // a la ves que se va obteniendo el total de la fatura 
                total += product.total* 1.15;
            }
            this.total = total;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            sb.append("\n factura " + this.id +"\n");
            for (Product product : products) {
                sb.append(product.toString());
                sb.append(" IVA: "+product.total*0.15+"$");
                sb.append("\n-------------------\n");
            }
            sb.append("Total con impuestos: $").append(this.total);
            return sb.toString();
        }
    }

    
    public static void main(String[] args) {
        // Manejador de solicitudes  
        boolean handlerSesion = true;

        // Flujo de ejecución 
        while (handlerSesion) {
            switch (menu()) {
                case 1:
                    // Registrar venta 
                    registerSale();
                    break;
                case 2:
                    // Listado de ventas
                    showSales();
                    break;
                case 3:
                    // Detener el programa 
                    System.out.println("Hasta pronto...");
                    handlerSesion = false;
                    break;
                default:
                    System.out.println("Opción no válida");
            }
        }
    }

     // Método para registrar una venta
     public static void registerSale() {
        System.out.println("\n Registro de venta -----------------------");

        List<Product> products = new ArrayList<>();
        // manejador de mensajes de error 
        boolean error;
        // manejador de agregado de productos
        boolean addProduct=true;

        while (addProduct) {
            System.out.println("\nProducto");
            
            // ingreso de datos del producto
            String name = GetInputString(" Nombre");
            double price = GetInputDouble(" Precio por unidad");
            String typeProduct;
            
            // ingresamos y validamoes el tipod e producto
            do {
                error = false;
                int type = GetInputInt("\n Tipo de producto -------- \n 1: entero \n 2: pesado \n Ingresa acá su respuesta: ");
                
                // Asignación condicionada segun el rtpo de producto selecionado
                typeProduct = (type == 1) ? "entero" : (type == 2) ? "pesado" : null;

                if (typeProduct == null) {
                    System.out.println("Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (1 o 2).");
                    error = true;
                }
                
            } while (error);
            

            Product product = new Product(name, price, typeProduct);
            product.setQuantity();
            products.add(product);

            do{
                error = false;
                int response = GetInputInt("\n ¿Desea agregar otro producto? -------- \n 1: Si \n 0: No \n Ingresa acá su respuesta: ");

                if (response<0 || response>1) {
                    System.out.println("Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (0 o 1).");
                    error = true;
                }
                else{
                    addProduct = (response == 1) ? true : false;
                }
            }while(error);
            
        }

        Sale sale = new Sale(products);
        salesList.add(sale);

        System.out.println("Venta registrada exitosamente:\n" + sale);
    }

    // Método para mostrar el listado de ventas
    public static void showSales() {
        if (salesList.isEmpty()) {
            System.out.println("No hay ventas registradas.");
        } else {
            System.out.println("Listado de Ventas:");
            for (Sale sale : salesList) {
                System.out.println(sale);
            }
        }
    }

    // Método manejador del menú
    public static int menu() {
        int option = -1;
        do {
            try {
                System.out.println("\n------------------------------");
                System.out.println("|    Gestor de Ventas        |");
                System.out.println("------------------------------");
                System.out.println("| 1: Registrar una venta     |");
                System.out.println("| 2: Listado de ventas       |");
                System.out.println("| 3: Salir del Programa      |");
                System.out.println("------------------------------");
                System.out.print("Selecciona una opción: ");
                option = input.nextInt();

                if (option <= 0 || option > 3) {
                    System.out.println("Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (1 a 3).");
                }
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next();
            }
        } while (option <= 0 || option > 3);

        return option;
    }

    // funciones para ingreso y validacion de valores segun el tipo  
    public static String GetInputString( String nameVar) {
        boolean error;
        String var;
        do {
            error = false;
            System.out.print(" " + nameVar + ": ");
            var = input.next();
            if (var == null || var.isEmpty()) {
                System.out.println("Valor inválido: Por favor no ingresar el prompt vacío");
                error = true;
            }
        } while (error);

        return var;
    }

    public static int GetInputInt( String nameVar) {
        boolean error;
        int var=0;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": ");
                var = input.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next();
                error = true;
            }
        } while (error);

        return var;
    }

    public static double GetInputDouble( String nameVar) {
        boolean error;
        double var=0.0;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": ");
                var = input.nextDouble();
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next();
                error = true;
            }
        } while (error);

        return var;
    }

}
