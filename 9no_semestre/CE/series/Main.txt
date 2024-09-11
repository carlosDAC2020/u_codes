/*
Estudiante
 - Carlos Daniel Agamez Palomino T00059006

    Reto: Calculadora de Series

    Descripción: 
    Crea un programa en Java que calcule e imprima las sumas de diferentes series numéricas. El usuario debe poder seleccionar la serie que desea calcular.

    Requisitos:
        - Utiliza una clase para modelar una serie numérica, incluyendo un atributo para el límite superior de la serie y un método para calcular la suma de la serie.
        - Implementa una clase CalculadoraSeries que permita al usuario seleccionar la serie a calcular (por ejemplo, serie aritmética, serie geométrica, etc.).
        - Utiliza estructuras de repetición (for, while o do-while) para calcular la suma de cada serie.
        - Maneja excepciones para validar que el límite superior ingresado por el usuario sea un número positivo.
        - Muestra mensajes claros al usuario durante la interacción con la calculadora de series.
*/


import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

// manejo de ventanas de infromacion 
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Main {
    
    public static Scanner input = new Scanner(System.in);

    // Códigos de color ANSI para estilos de imprecion
    public static final String RESET = "\033[0m";  // Resetea el color
    public static final String RED = "\033[31m";
    public static final String GREEN = "\033[32m";
    public static final String CYAN = "\033[36m";

    // clases majeadoras de los tipos de serie 
    public static abstract class NumericSeries {
        protected double firstTerm;
        protected int numtTerms;

        public NumericSeries(double firstTerm, int numtTerms) {
            this.firstTerm = firstTerm;
            this.numtTerms = numtTerms;
        }

        public abstract double calculateSum();
        public abstract void displaySeries();
    }

    public static class ArithmeticSeries extends NumericSeries {
        private double difference;
    
        public ArithmeticSeries(double firstTerm, int numtTerms, double difference) {
            super(firstTerm, numtTerms);
            this.difference = difference;
        }
    
        @Override
        public double calculateSum() {
            double sum = 0.0;
            double currentTerm = firstTerm;

            // Sumar cada término de la serie
            for (int i = 0; i < numtTerms; i++) {
                sum += currentTerm;
                currentTerm += difference;
            }

            return sum;
        }

        @Override
        public void displaySeries() {
            System.out.print("[");
            for (int i = 0; i < numtTerms; i++) {
                double term = firstTerm + i * difference;
                System.out.print(term + " ");
            }
            System.out.print("]");
        }

    
    }

    public static class GeometricSeries extends NumericSeries {
        private double ratio;
    
        public GeometricSeries(double firstTerm, int numtTerms, double ratio) {
            super(firstTerm, numtTerms);
            this.ratio = ratio;
        }
    
        @Override
        public double calculateSum() {
            double sum = 0.0;
            double currentTerm = firstTerm;
            
            // Calcular la suma de manera iterativa
            for (int i = 0; i < numtTerms; i++) {
                sum += currentTerm;
                currentTerm *= ratio;
            }
            
            return sum;
        }
    
        @Override
        public void displaySeries() {
            double currentTerm = firstTerm;
            System.out.print("[");
            for (int i = 0; i < numtTerms; i++) {
                System.out.print(currentTerm + ", ");
                currentTerm *= ratio;
            }
            System.out.print("]");
        }

    }
    
    public static class FibonacciSeries extends NumericSeries {
        private double secondTerm;

        public FibonacciSeries(double firstTerm, double secondTerm, int numtTerms) {
            super(firstTerm, numtTerms);
            this.secondTerm = secondTerm;
        }

        @Override
        public double calculateSum() {
            if (numtTerms == 0) return 0;

            double sum = 0.0;
            double a = firstTerm;
            double b = secondTerm;

            sum += a;
            if (numtTerms > 1) sum += b;

            for (int i = 2; i < numtTerms; i++) {
                double nextTerm = a + b;
                sum += nextTerm;
                a = b;
                b = nextTerm;
            }

            return sum;
        }

        @Override
        public void displaySeries() {
            double a = firstTerm;
            double b = secondTerm;

            System.out.print("["+ a + " ");
            if (numtTerms > 1) System.out.print(b + ", ");

            for (int i = 2; i < numtTerms; i++) {
                double nextTerm = a + b;
                System.out.print(nextTerm + ", ");
                a = b;
                b = nextTerm;
            }
            System.out.print("]");
        }

    
    }

    // clase para ventana de informacion 
    public static class SeriesInfoWindow extends JFrame {
        // Lista estática para almacenar las ventanas abiertas
        private static final List<SeriesInfoWindow> openWindows = new ArrayList<>();

        public SeriesInfoWindow(String title, String content) {
            setTitle(title);
            setSize(500, 400);
            setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            setLocationRelativeTo(null); // Centrar la ventana en la pantalla

            JEditorPane editorPane = new JEditorPane();
            editorPane.setContentType("text/html");
            editorPane.setText(content);
            editorPane.setEditable(false);

            JScrollPane scrollPane = new JScrollPane(editorPane);
            add(scrollPane);

            // Agrega la ventana actual a la lista de ventanas abiertas
            openWindows.add(this);

            // Elimina la ventana de la lista al cerrarse
            addWindowListener(new WindowAdapter() {
                @Override
                public void windowClosed(WindowEvent e) {
                    openWindows.remove(SeriesInfoWindow.this);
                }
            });
        }
        
        public static void closeAllWindows() {
            for (SeriesInfoWindow window : new ArrayList<>(openWindows)) {
                window.dispose();
            }
            openWindows.clear();
        }
    }

    // informacion amostrar de los tipos de serie 
    public class SeriesInfo {

        public static void showArithmeticSeriesInfo() {
            String content = "<html><body>" +
                    "<h2>Serie Aritmética</h2>" +
                    "<p>Una serie aritmética es una secuencia de números en la que la diferencia entre términos consecutivos es constante.</p>" +
                    "<p><b>Atributos:</b></p>" +
                    "<ul>" +
                    "<li><b>Primer Término:</b> El primer número de la serie.</li>" +
                    "<li><b>Diferencia:</b> La diferencia común entre términos consecutivos.</li>" +
                    "<li><b>Número de Términos:</b> La cantidad de términos en la serie.</li>" +
                    "</ul>" +
                    "<img src='https://nemdigitalstorage.blob.core.windows.net/nem-main/images/2023/05/27/76424907-3c17-4e5c-864e-806106950dc7.png' width='400'/>" +
                    "<p><b>Ejemplo:</b> Si a_1 = 2, d = 3, y n = 5, la serie es: 2, 5, 8, 11, 14</p>" +
                    "</body></html>";
            new SeriesInfoWindow("Información sobre Serie Aritmética", content).setVisible(true);
        }
        
        public static void showGeometricSeriesInfo() {
            String content = "<html><body>" +
                    "<h2>Serie Geométrica</h2>" +
                    "<p>Una serie geométrica es una secuencia de números en la que cada término después del primero se obtiene multiplicando el término anterior por una constante.</p>" +
                    "<p><b>Atributos:</b></p>" +
                    "<ul>" +
                    "<li><b>Primer Término:</b> El primer número de la serie.</li>" +
                    "<li><b>Razón:</b> La constante por la que se multiplica cada término para obtener el siguiente.</li>" +
                    "<li><b>Número de Términos:</b> La cantidad de términos en la serie.</li>" +
                    "</ul>" +
                    "<img src='https://i.ytimg.com/vi/cacwZZoHzjQ/maxresdefault.jpg' width='400'/>" +
                    "<p><b>Ejemplo:</b> Si a_1 = 3, r = 2, y n = 4, la serie es: 3, 6, 12, 24</p>" +
                    "</body></html>";
            new SeriesInfoWindow("Información sobre Serie Geométrica", content).setVisible(true);
        }
        
        public static void showFibonacciSeriesInfo() {
            String content = "<html><body>" +
                    "<h2>Serie Fibonacci</h2>" +
                    "<p>Una serie de Fibonacci es una secuencia en la que cada término es la suma de los dos términos anteriores.</p>" +
                    "<p><b>Atributos:</b></p>" +
                    "<ul>" +
                    "<li><b>Primer Término:</b> El primer número de la serie.</li>" +
                    "<li><b>Segundo Término:</b> El segundo número de la serie.</li>" +
                    "<li><b>Número de Términos:</b> La cantidad de términos en la serie.</li>" +
                    "</ul>" +
                    "<img src='https://www.esferatic.com/wp-content/uploads/2012/11/fibonacci_n.jpg' width='400'/>" +
                    "<p><b>Ejemplo:</b> Si los primeros dos términos son 0 y 1, y n = 5, la serie es: 0, 1, 1, 2, 3</p>" +
                    "</body></html>";
            new SeriesInfoWindow("Información sobre Serie Fibonacci", content).setVisible(true);
        }
    }
    
    public static void main(String[] args) {
        boolean handlerSesion = true;
        int numtTerms;
        double firstTerm, secondTerm;
        while (handlerSesion) {
            switch (menu()) {
                case 1:
                    System.out.println("\n---------- Serie Aritmética ----------");
                    // Mostrar información de la serie
                    SeriesInfo.showArithmeticSeriesInfo();
                    
                    // Solicitar los datos al usuario
                    firstTerm = GetInputDouble("Ingrese el primer término");
                    do {
                        numtTerms = GetInputInt("Ingrese el número de términos");
                        if(numtTerms <= 0) {
                            System.out.println(RED+"Valor inválido: ingresar solo valores mayores a 0 \n"+RESET);
                        }    
                    } while (numtTerms <= 0);
                    
                    double difference = GetInputDouble("Ingrese la diferencia común");

                    // Crear instancia de ArithmeticSeries
                    ArithmeticSeries arithmeticSeries = new ArithmeticSeries(firstTerm, numtTerms, difference);

                    // Calcular y mostrar la suma
                    double sumAritmetic = arithmeticSeries.calculateSum();
                    System.out.println(" La suma de la serie es: "+ GREEN + sumAritmetic + RESET);

                    // Mostrar la serie
                    System.out.println(" serie generada: ");
                    arithmeticSeries.displaySeries();

                    // cerrar vemtana de informacion de forma automatica 
                    SeriesInfoWindow.closeAllWindows();
                    break;

                case 2:
                    System.out.println("\n---------- Serie Geométrica ----------");
                    
                    // Mostrar información de la serie
                    SeriesInfo.showGeometricSeriesInfo();

                    // Solicitar los datos al usuario
                    firstTerm = GetInputDouble("Ingrese el primer término");
                    do {
                        numtTerms = GetInputInt("Ingrese el número de términos");
                        if(numtTerms <= 0) {
                            System.out.println(RED+"Valor inválido: ingresar solo valores mayores a 0 \n"+RESET);
                        }    
                    } while (numtTerms <= 0);
                    
                    double ratio = GetInputDouble("Ingrese la razón común");

                    // Crear instancia de GeometricSeries
                    GeometricSeries geometricSeries = new GeometricSeries(firstTerm, numtTerms, ratio);

                    // Calcular y mostrar la suma
                    double sumGeometric = geometricSeries.calculateSum();
                    System.out.println(" La suma de la serie es: " +GREEN+ sumGeometric +RESET);

                    // Mostrar la serie
                    System.out.println(" serie generada: ");
                    geometricSeries.displaySeries();

                    // cerrar vemtana de informacion de forma automatica 
                    SeriesInfoWindow.closeAllWindows();
                    break;

                case 3:
                    System.out.println("\n---------- Serie Fibonacci ----------");
                    
                    // Mostrar información de la serie
                    SeriesInfo.showFibonacciSeriesInfo();

                    // Solicitar los dos términos iniciales y la cantidad de términos al usuario
                    firstTerm = GetInputDouble("Ingrese el primer término inicial");
                    secondTerm = GetInputDouble("Ingrese el segundo término inicial");
                    do {
                        numtTerms = GetInputInt("Ingrese el número de términos");
                        if(numtTerms <= 0) {
                            System.out.println(RED+"Valor inválido: ingresar solo valores mayores a 0 \n"+RESET);
                        }    
                    } while (numtTerms <= 0);

                    // Crear instancia de FibonacciSeries
                    FibonacciSeries fibonacciSeries = new FibonacciSeries(firstTerm, secondTerm, numtTerms);

                    // Calcular y mostrar la suma
                    double sumFibonacci = fibonacciSeries.calculateSum();
                    System.out.println(" La suma de la serie es: " + GREEN + sumFibonacci + RESET);

                    // Mostrar la serie
                    System.out.println(" serie generada: ");
                    fibonacciSeries.displaySeries();

                    // cerrar vemtana de informacion de forma automatica 
                    SeriesInfoWindow.closeAllWindows();
                    break;

                case 4:
                    System.out.println("Hasta pronto...");
                    handlerSesion = false;
                    break;
                default:
                    System.out.println("Opción no válida");
            }
        }
    }

    public static int menu() {
        int option = -1;
        do {
            try {
                System.out.println("\n---------------------------------");
                System.out.println("|       Calculadora de Series   |");
                System.out.println("---------------------------------");
                System.out.println("| 1: Serie Aritmética           |");
                System.out.println("| 2: Serie Geométrica           |");
                System.out.println("| 3: Serie Fibonacci            |");
                System.out.println("| 4: Salir del Programa         |");
                System.out.println("---------------------------------");
                option = GetInputInt("Selecciona una opción");

                if (option <= 0 || option > 4) {
                    System.out.println(RED+"Valor inválido: Ingresar solo valores ubicados en el rango dispuesto (1 a 4)."+RESET);
                }
            } catch (InputMismatchException e) {
                System.out.println(RED+"Valor inválido: Por favor ingresar solo valores numéricos."+RESET);
                input.next();
            }
        } while (option <= 0 || option > 4);

        return option;
    }
    
    public static int GetInputInt(String nameVar) {
        boolean error;
        int var = 0;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": "+CYAN);
                var = input.nextInt();
                System.out.print(RESET);
            } catch (InputMismatchException e) {
                System.out.println(RED+"Valor inválido: Por favor ingresar solo valores numéricos."+RESET);
                input.next();
                error = true;
            }
        } while (error);

        return var;
    }

    public static double GetInputDouble(String nameVar) {
        boolean error;
        double var = 0.0;
        do {
            try {
                error = false;
                System.out.print(" " + nameVar + ": "+CYAN);
                var = input.nextDouble();
                System.out.print(RESET);
            } catch (InputMismatchException e) {
                System.out.println(RED+"Valor inválido: Por favor ingresar solo valores numéricos."+RESET);
                input.next();
                error = true;
            }
        } while (error);

        return var;
    }
}
