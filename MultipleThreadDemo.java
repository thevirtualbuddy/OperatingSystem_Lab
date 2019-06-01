public class MultipleThreadDemo {

    private static class ParallelTask implements Runnable {

        @Override
        public void run() {
            System.out.println(Thread.currentThread().getName()
                    );

        }

    }

    public static void main(String[] args) {

        // created three threads but none will start until you call
        // start() method
        Thread t1 = new Thread(new ParallelTask(), "Hello Thread 1");
        Thread t2 = new Thread(new ParallelTask(), "Hello Thread 2");

        // now, let's start all three threads
        t1.start();
        t2.start();
    }

}


