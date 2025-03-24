/**
 * La clase Hilos extiende la clase Thread y se utiliza para crear y ejecutar hilos.
 * Cada hilo imprime un mensaje en cada iteración de un bucle y al finalizar su ejecución.
 */
public class Hilos extends Thread {

    /**
     * Constructor de la clase Hilos.
     * 
     * @param nombre El nombre que se le asignará al hilo.
     */
    public Hilos(String nombre){
        super(nombre);
    }

    /**
     * Método run que contiene el código que se ejecutará cuando el hilo sea iniciado.
     * Este método realiza 5 iteraciones e imprime un mensaje con el número de iteración 
     * y el nombre del hilo. Al finalizar, imprime un mensaje indicando que el hilo ha terminado.
     */
    @Override
    public void run(){
        // Bucle que imprime el número de iteración del hilo.
        for (int i = 0; i < 5; i++) {
            System.out.println("Iteracion "+ (i+1) + " de "+ getName());
        }
        // Mensaje final al terminar la ejecución del hilo.
        System.out.println("Termina el " + getName());
    }

    /**
     * Método main que inicia la ejecución de dos hilos con nombres específicos y
     * luego imprime un mensaje indicando que el hilo principal ha terminado.
     * 
     * @param args Argumentos de la línea de comandos (no utilizados en este caso).
     */
    public static void main(String[] args) {
        // Se crean e inician dos hilos con nombres "Primer hilo", "Segundo hilo" y "Tercer hilo".
        new Hilos("Primer hilo").start();
        new Hilos("Segundo hilo").start();
        new Hilos("Tercer hilo").start();
        // Mensaje que indica que el hilo principal ha terminado su ejecución.
        System.out.println("Termina el hilo principal");
    }
}