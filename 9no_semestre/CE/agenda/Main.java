import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;

public class Main {

    // Manejador de entradas desde teclado
    public static Scanner input = new Scanner(System.in);

    // Clase contacto
    public static class Contact {
        private int id;
        private String firstName;
        private String lastName;
        private String phone;
        private String email;

        public Contact(int id, String firstName, String lastName, String phone, String email) {
            this.id = id;
            this.firstName = firstName;
            this.lastName = lastName;
            this.phone = phone;
            this.email = email;
        }

        @Override
        public String toString() {
            return "\n Contacto{" +
                    "\n   Id: " + id  +
                    "\n   Nombre: " + firstName  +
                    "\n   Apellido: " + lastName +
                    "\n   Telefono: " + phone +
                    "\n   Email: " + email +"\n"+
                    '}';
        }
    }

    // Clase agenda 
    public static class Agenda {
        private ArrayList<Contact> contacts;

        public Agenda() {
            this.contacts = new ArrayList<>();
        }

        public void addContact(Contact contact) {
            contacts.add(contact);
        }

        public void addContact() {
            // Manejador de mensajes de error
            boolean messageError=false;
        
            String firstName, lastName, email, phone;
            int id;
        
            System.out.println("\n AÑADIR CONTACTO");
            firstName = GetInputString("", "Nombre");
            lastName = GetInputString("", "Apellido");
        
            // Validar teléfono
            do {
                phone = GetInputString("", "Teléfono");
                messageError = phone.length() != 10 || !phone.matches("\\d+");  
                // Se valida la cantidad exacta de dígitos y que solo contenga números
                if (messageError) {
                    System.out.println("\n Número de teléfono inválido: debe contener exactamente 10 dígitos y no debe contener letras.");
                }
            } while (messageError);
        
            // Validar email
            do {
                email = GetInputString("", "Email");
                messageError = !email.matches("^[\\w._%+-]+@[\\w.-]+\\.[a-zA-Z]{2,6}$");
                if (messageError) {
                    System.out.println("\n Email inválido: debe contener un '@' y terminar con una extensión válida.");
                }
            } while (messageError);
            
            // Validar si el contacto ya existe
            if (contactExists(firstName, lastName, phone, email)) {
                System.out.println("\n El contacto ya existe en la lista.");
                return;
            }
            // Obtener el id del último contacto agregado + 1
            id = contacts.isEmpty() ? 0 : contacts.get(contacts.size() - 1).id + 1;
            Contact contact = new Contact(id, firstName, lastName, phone, email);
            addContact(contact);
        }        

        public void deleteContact() {
            System.out.println("\n ELIMINAR CONTACTO");

            // Preguntar al usuario si desea ver la lista de contactos antes de eliminar
            System.out.print("¿Desea ver la lista de contactos antes de eliminar? (s/n): ");
            String respuesta = input.next();

            if (respuesta.equalsIgnoreCase("s")) {
                displayContacts();
            }

            System.out.println();

            int id = GetInputInt(0, "Id");

            Iterator<Contact> iterator = contacts.iterator();
            boolean found = false;
            while (iterator.hasNext()) {
                Contact contact = iterator.next();
                if (contact.id == id) {
                    iterator.remove();
                    System.out.println(" Contacto eliminado exitosamente.");
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println(" No se encontró ningún contacto con ese id.");
            }
        }

        public void searchContact() {
            System.out.println("\n BUSCAR CONTACTO");
            int id = GetInputInt(0, "Id");

            boolean found = false;
            for (Contact contact : contacts) {
                if (contact.id == id) {
                    System.out.println(" Contacto encontrado:");
                    System.out.println(contact.toString());
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println(" No se encontró ningún contacto con ese id.");
            }
        }

        public void displayContacts() {
            System.out.println("\n LISTA DE CONTACTOS.");
            if (contacts.isEmpty()) {
                System.out.println(" Lista de Contactos vacía.");
            } else {
                for (Contact contact : contacts) {
                    System.out.println(contact.toString());
                }
            }
        }

        // verificador de existencia de contsatos 
        public boolean contactExists(String firstName, String lastName, String phone, String email) {
            for (Contact contact : contacts) {
                if (contact.firstName.equalsIgnoreCase(firstName) &&
                    contact.lastName.equalsIgnoreCase(lastName) &&
                    contact.phone.equals(phone) &&
                    contact.email.equalsIgnoreCase(email)) {
                    return true;
                }
            }
            return false;
        }
    }

    public static void main(String[] args) {
        // Crear una nueva agenda 
        Agenda agenda = new Agenda();

        // Crear algunos contactos de prueba
        Contact contacto1 = new Contact(0,"Carlos", "Agamez", "1234567890", "carlos@example.com");
        Contact contacto2 = new Contact(1,"María", "Gómez", "9876543210", "maria@example.com");
        Contact contacto3 = new Contact(2,"Juan", "Pérez", "4567891230", "juan@example.com");

        // Agregar los contactos de prueba a la agenda
        agenda.addContact(contacto1);
        agenda.addContact(contacto2);
        agenda.addContact(contacto3);

        // Manejador de solicitudes  
        boolean handlerSesion = true;

        // Flujo de ejecución 
        while (handlerSesion) {
            switch (menu()) {
                case 1:
                    agenda.displayContacts();
                    break;
                case 2:
                    agenda.addContact();
                    break;
                case 3:
                    agenda.deleteContact();
                    break;
                case 4:
                    agenda.searchContact();
                    break;
                case 5:
                    // Detener el programa 
                    System.out.println("Hasta pronto...");
                    handlerSesion = false;
                    break;
                default:
                    System.out.println("Opción no válida");
            }
        }
    }

    // Método manejador del menú
    public static int menu() {
        int option = -1;
        do {
            try {
                System.out.println("\n---------------------------------");
                System.out.println("|       Agenda de Contactos     |");
                System.out.println("---------------------------------");
                System.out.println("| 1: Mostrar lista de Contactos |");
                System.out.println("| 2: Agregar Contacto           |");
                System.out.println("| 3: Eliminar Contacto          |");
                System.out.println("| 4: Buscar Contacto            |");
                System.out.println("| 5: Salir del Programa         |");
                System.out.println("---------------------------------");
                System.out.print("Selecciona una opción: ");
                option = input.nextInt();

                if (option <= 0 || option > 5) {
                    System.out.println("Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (1 a 5).");
                }
            } catch (InputMismatchException e) {
                System.out.println("Valor inválido: Por favor ingresar solo valores numéricos.");
                input.next();
            }
        } while (option <= 0 || option > 5);

        // Retorno de opción 
        return option;
    }

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

    public static int GetInputInt(int var, String nameVar) {
        boolean error;
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
}
