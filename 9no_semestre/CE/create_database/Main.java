import java.sql.*;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {

    // Manejador de entradas desde teclado
    public static Scanner input = new Scanner(System.in);
    private static Connection connection;

    // Clase Producto
    public static class Producto {
        private int id;
        private String nombre;
        private String descripcion;
        private double precio;
        private int cantidad;

        public Producto(int id, String nombre, String descripcion, double precio, int cantidad) {
            this.id = id;
            this.nombre = nombre;
            this.descripcion = descripcion;
            this.precio = precio;
            this.cantidad = cantidad;
        }

        @Override
        public String toString() {
            return "\n Producto{" +
                    "\n   ID: " + id +
                    "\n   Nombre: " + nombre +
                    "\n   Descripción: " + descripcion +
                    "\n   Precio: " + precio +
                    "\n   Cantidad: " + cantidad + "\n" +
                    '}';
        }
    }

    // Método para conectar a la base de datos
    private static void connectToDatabase() {
        try {
            String URL = "jdbc:mysql://127.0.0.1:3306/inventario";
            String user = "user";
            String password = "password";
            connection = DriverManager.getConnection(URL, user, password);
            System.out.println("Conexión a la base de datos establecida.");
        } catch (SQLException e) {
            System.out.println("Error de conexión: " + e.getMessage());
        }
    }

    // Clase Inventario
    public static class Inventario {
        private ArrayList<Producto> productos;

        public Inventario() {
            productos = new ArrayList<>();
        }

        public void agregarProducto(Producto producto) {
            String sql = "INSERT INTO producto (id, nombre, descripcion, precio, stock) VALUES (?, ?, ?, ?, ?)";
            try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
                pstmt.setInt(1, producto.id);
                pstmt.setString(2, producto.nombre);
                pstmt.setString(3, producto.descripcion);
                pstmt.setDouble(4, producto.precio);
                pstmt.setInt(5, producto.cantidad);
                pstmt.executeUpdate();
                System.out.println("Producto agregado exitosamente a la base de datos.");
                productos.add(producto); // Agregar a la lista local
            } catch (SQLException e) {
                System.out.println("Error al agregar producto: " + e.getMessage());
            }
        }

        public void eliminarProducto(int id) {
            String sql = "DELETE FROM producto WHERE id = ?";
            try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
                pstmt.setInt(1, id);
                int rowsAffected = pstmt.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Producto eliminado exitosamente.");
                    productos.removeIf(p -> p.id == id); // Eliminar de la lista local
                } else {
                    System.out.println("No se encontró ningún producto con ese ID.");
                }
            } catch (SQLException e) {
                System.out.println("Error al eliminar producto: " + e.getMessage());
            }
        }

        public Producto buscarProductoPorId(int id) {
            String sql = "SELECT * FROM producto WHERE id = ?";
            try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
                pstmt.setInt(1, id);
                ResultSet rs = pstmt.executeQuery();
                if (rs.next()) {
                    return new Producto(
                        rs.getInt("id"),
                        rs.getString("nombre"),
                        rs.getString("descripcion"),
                        rs.getDouble("precio"),
                        rs.getInt("stock")
                    );
                } else {
                    System.out.println("No se encontró ningún producto con ese ID.");
                }
            } catch (SQLException e) {
                System.out.println("Error al buscar producto: " + e.getMessage());
            }
            return null;
        }

        public void mostrarProductos() {
            String sql = "SELECT * FROM producto";
            try (Statement stmt = connection.createStatement();
                 ResultSet rs = stmt.executeQuery(sql)) {
                System.out.println("\nLISTA DE PRODUCTOS:");
                while (rs.next()) {
                    Producto producto = new Producto(
                        rs.getInt("id"),
                        rs.getString("nombre"),
                        rs.getString("descripcion"),
                        rs.getDouble("precio"),
                        rs.getInt("stock")
                    );
                    productos.add(producto); // Agregar a la lista local
                    System.out.println(producto);
                }
            } catch (SQLException e) {
                System.out.println("Error al mostrar productos: " + e.getMessage());
            }
        }
    }

    public static void main(String[] args) {
        connectToDatabase();
        Inventario inventario = new Inventario();

        // Flujo de ejecución 
        boolean continuar = true;
        while (continuar) {
            switch (menu()) {
                case 1:
                    
                    inventario.mostrarProductos();
                    break;
                case 2:
                    System.out.println("\nAGREGAR PRODUCTO");
                    agregarProducto(inventario);
                    break;
                case 3:
                    System.out.println("\nELIMINAR PRODUCTO");
                    eliminarProducto(inventario);
                    break;
                case 4:
                    System.out.println("\nBUSCAR PRODUCTO");
                    buscarProducto(inventario);
                    break;
                case 5:
                    System.out.println("Hasta pronto...");
                    continuar = false;
                    break;
                default:
                    System.out.println("Opción no válida.");
            }
        }


        // Cerrar la conexión al finalizar
        try {
            if (connection != null && !connection.isClosed()) {
                connection.close();
                System.out.println("Conexión a la base de datos cerrada.");
            }
        } catch (SQLException e) {
            System.out.println("Error al cerrar la conexión: " + e.getMessage());
        }
    }

    // Método para mostrar el menú
    public static int menu() {
        int opcion = -1;
        do {
            try {
                System.out.println("\n---------------------------------");
                System.out.println("|     Sistema de Inventario     |");
                System.out.println("---------------------------------");
                System.out.println("| 1: Mostrar lista de Productos  |");
                System.out.println("| 2: Agregar Producto            |");
                System.out.println("| 3: Eliminar Producto           |");
                System.out.println("| 4: Buscar Producto             |");
                System.out.println("| 5: Salir del Programa          |");
                System.out.println("---------------------------------");
                System.out.print("Selecciona una opción: ");
                opcion = input.nextInt();

                if (opcion <= 0 || opcion > 5) {
                    System.out.println("Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (1 a 5).");
                }
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next(); // Limpiar entrada
            }
        } while (opcion <= 0 || opcion > 5);

        return opcion;
    }

    // Agregar producto
    public static void agregarProducto(Inventario inventario) {
        String nombre = GetInputString("", "Nombre del Producto");
        String descripcion = GetInputString("", "Descripción del Producto");
        double precio = GetInputDouble(0.0, "Precio del Producto");
        int cantidad = GetInputInt(0, "Cantidad en Stock");

        int id = inventario.productos.isEmpty() ? 0 : inventario.productos.get(inventario.productos.size() - 1).id + 1;
        Producto producto = new Producto(id, nombre, descripcion, precio, cantidad);
        inventario.agregarProducto(producto);
    }

    // Eliminar producto
    public static void eliminarProducto(Inventario inventario) {
        int id = GetInputInt(0, "ID del Producto a Eliminar");
        inventario.eliminarProducto(id);
    }

    // Buscar producto
    public static void buscarProducto(Inventario inventario) {
        int id = GetInputInt(0, "ID del Producto a Buscar");
        Producto producto = inventario.buscarProductoPorId(id);
        if (producto != null) {
            System.out.println("Producto encontrado:");
            System.out.println(producto.toString());
        }
    }

    // Obtener entrada de cadena
    public static String GetInputString(String var, String nameVar) {
        boolean error;
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

    // Obtener entrada de entero
    public static int GetInputInt(int var, String nameVar) {
        boolean error;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": ");
                var = input.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next(); // Limpiar entrada
                error = true;
            }
        } while (error);
        return var;
    }

    // Obtener entrada de doble
    public static double GetInputDouble(double var, String nameVar) {
        boolean error;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": ");
                var = input.nextDouble();
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next(); // Limpiar entrada
                error = true;
            }
        } while (error);
        return var;
    }
}
