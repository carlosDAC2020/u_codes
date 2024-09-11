
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.Set;
import java.util.ArrayList;
import java.util.List;

public class nn {
    public static void main(String[] args) {
        Agenda miAgenda = new Agenda(); // Crear una agenda sin límite de capacidad
        Scanner scanner = new Scanner(System.in);
        int opcion = 0;
        boolean entradaValida;

        do {
            entradaValida = false;
            System.out.println("\n1. Agregar contacto");
            System.out.println("2. Eliminar contacto");
            System.out.println("3. Buscar contacto");
            System.out.println("4. Mostrar todos los contactos");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opción: ");

            try {
                opcion = scanner.nextInt();
                scanner.nextLine(); // Limpiar buffer
                if (opcion < 1 || opcion > 5) {
                    System.out.println("Opción no válida. Debe ingresar un número entre 1 y 5.");
                } else {
                    entradaValida = true; // Solo se asigna true si la opción es válida
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada no válida. Debe ingresar un número.");
                scanner.next(); // Limpiar el buffer de entrada
            }

            if (entradaValida) {
                switch (opcion) {
                    case 1:
                        agregarContacto(scanner, miAgenda);
                        break;

                    case 2:
                        System.out.print("Ingrese el nombre del contacto a eliminar: ");
                        String nombreEliminar = scanner.nextLine();
                        miAgenda.eliminarContacto(nombreEliminar);
                        break;

                    case 3:
                        System.out.print("Ingrese el nombre del contacto a buscar: ");
                        String nombreBuscar = scanner.nextLine();
                        miAgenda.buscarContacto(nombreBuscar);
                        break;

                    case 4:
                        miAgenda.mostrarTodosLosContactos();
                        break;

                    case 5:
                        System.out.println("Saliendo del programa...");
                        break;

                    default:
                        System.out.println("Opción no válida.");
                }
            }

        } while (opcion != 5);

        scanner.close();
    }

    private static void agregarContacto(Scanner scanner, Agenda miAgenda) {
        String nombre, apellido, telefono, email;
        boolean telefonoValido, emailValido;

        System.out.print("Ingrese nombre: ");
        nombre = scanner.nextLine();
        System.out.print("Ingrese apellido: ");
        apellido = scanner.nextLine();

        do {
            System.out.print("Ingrese teléfono (10 dígitos, empieza con 3): ");
            telefono = scanner.nextLine();
            telefonoValido = telefono.matches("^3\\d{9}$");

            if (telefonoValido) {
                if (miAgenda.telefonoExiste(telefono)) {
                    System.out.println("El número de teléfono ya existe en la agenda.");
                    int respuesta;
                    do {
                        System.out.print("¿Desea corregirlo? (1 para sí, 0 para no): ");
                        respuesta = leerRespuesta(scanner);
                        if (respuesta == 0) {
                            System.out.println("Saliendo al menú principal...");
                            return; // Salir del método para regresar al menú
                        }
                    } while (respuesta != 1); // Solo se permite corregir con 1
                } else {
                    break; // Salir del bucle si el teléfono es válido y único
                }
            } else {
                System.out.println("Número de teléfono inválido. Debe tener 10 dígitos y comenzar con 3.");
                int respuesta;
                do {
                    System.out.print("¿Desea corregirlo? (1 para sí, 0 para no): ");
                    respuesta = leerRespuesta(scanner);
                    if (respuesta == 0) {
                        System.out.println("Saliendo al menú principal...");
                        return; // Salir del método para regresar al menú
                    }
                } while (respuesta != 1); // Solo se permite corregir con 1
            }
        } while (true);

        do {
            System.out.print("Ingrese correo electrónico: ");
            email = scanner.nextLine();
            emailValido = email.matches("^[\\wñÑ\\.-]+@[\\wñÑ\\.-]+\\.(com|co)$");
            if (!emailValido || miAgenda.emailExiste(email)) {
                if (!emailValido) {
                    System.out.println("Correo electrónico inválido. Debe contener '@' y terminar en '.com' o '.co'.");
                } else {
                    System.out.println("El correo electrónico ya existe en la agenda.");
                }
                int respuesta;
                do {
                    System.out.print("¿Desea corregirlo? (1 para sí, 0 para no): ");
                    respuesta = leerRespuesta(scanner);
                    if (respuesta == 0) {
                        System.out.println("Saliendo al menú principal...");
                        return; // Salir del método para regresar al menú
                    }
                } while (respuesta != 1); // Solo se permite corregir con 1
            } else {
                break; // Salir del bucle si el correo electrónico es válido y único
            }
        } while (true);

        try {
            miAgenda.agregarContacto(new Contacto(nombre, apellido, telefono, email));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    private static int leerRespuesta(Scanner scanner) {
        while (true) {
            try {
                int respuesta = scanner.nextInt();
                scanner.nextLine(); // Limpiar buffer
                if (respuesta == 1 || respuesta == 0) {
                    return respuesta;
                } else {
                    System.out.println("Opción no válida. Debe ingresar 1 para sí o 0 para no.");
                }
            } catch (InputMismatchException e) {
                System.out.println("Entrada no válida. Debe ingresar un número.");
                scanner.next(); // Limpiar el buffer de entrada
            }
        }
    }
}

class Contacto {
    private String nombre;
    private String apellido;
    private String telefono;
    private String email;

    public Contacto(String nombre, String apellido, String telefono, String email) throws Exception {
        if (!telefono.matches("^3\\d{9}$")) {
            throw new Exception("El número de teléfono debe tener 10 dígitos y comenzar con el número 3.");
        }
        if (!email.matches("^[\\wñÑ\\.-]+@[\\wñÑ\\.-]+\\.(com|co)$")) {
            throw new Exception("El correo electrónico debe contener '@' y terminar en '.com' o '.co'.");
        }
        this.nombre = nombre;
        this.apellido = apellido;
        this.telefono = telefono;
        this.email = email;
    }

    public String getNombre() {
        return nombre;
    }

    @Override
    public String toString() {
        return "Nombre: " + nombre + " " + apellido + ", Teléfono: " + telefono + ", Email: " + email;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getEmail() {
        return email;
    }
}

class Agenda {
    private List<Contacto> contactos;
    private Set<String> telefonos;
    private Set<String> emails;

    public Agenda() {
        contactos = new ArrayList<>();
        telefonos = new HashSet<>();
        emails = new HashSet<>();
    }

    public void agregarContacto(Contacto contacto) throws Exception {
        if (telefonos.contains(contacto.getTelefono())) {
            throw new Exception("El número de teléfono ya existe en la agenda.");
        }
        if (emails.contains(contacto.getEmail())) {
            throw new Exception("El correo electrónico ya existe en la agenda.");
        }
        contactos.add(contacto);
        telefonos.add(contacto.getTelefono());
        emails.add(contacto.getEmail());
        System.out.println("Contacto agregado exitosamente.");
    }

    public void eliminarContacto(String nombre) {
        boolean encontrado = false;
        for (int i = 0; i < contactos.size(); i++) {
            if (contactos.get(i).getNombre().equalsIgnoreCase(nombre)) {
                telefonos.remove(contactos.get(i).getTelefono());
                emails.remove(contactos.get(i).getEmail());
                contactos.remove(i);
                encontrado = true;
                System.out.println("Contacto eliminado exitosamente.");
                break;
            }
        }
        if (!encontrado) {
            System.out.println("Contacto no encontrado.");
        }
    }

    public void buscarContacto(String nombre) {
        boolean encontrado = false;
        for (Contacto contacto : contactos) {
            if (contacto.getNombre().equalsIgnoreCase(nombre)) {
                System.out.println(contacto);
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            System.out.println("Contacto no encontrado.");
        }
    }

    public boolean telefonoExiste(String telefono) {
        return telefonos.contains(telefono);
    }

    public boolean emailExiste(String email) {
        return emails.contains(email);
    }

    public void mostrarTodosLosContactos() {
        if (contactos.isEmpty()) {
            System.out.println("No hay contactos en la agenda.");
        } else {
            System.out.println("Total de contactos: " + contactos.size());
            for (Contacto contacto : contactos) {
                System.out.println(contacto);
            }
        }
    }
}
