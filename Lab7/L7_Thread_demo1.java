/* 1*/ public class L7_Thread_demo1 {
/* 2*/      public static void main(String[] args) {
                System.out.println("Main Thread ID: " + Thread.currentThread().getId());
/* 3*/          L7_Obj x = new L7_Obj();
/* 4*/          Thread t1 = new Thread(new WorkerDemo1(x));
/* 5*/          t1.start();
/* 6*/          Thread t2 = new Thread(new WorkerDemo2(x));
/* 7*/          t2.start();
/* 8*/          try {
/* 9*/              t1.join();
/*10*/              t2.join();
/*11*/          } catch (Exception e) { System.out.println(e); }
/*12*/          System.out.println("from main x value is " +
                x.getValue());
/*13*/      }
/*14*/ }

/*15*/ class WorkerDemo1 implements Runnable {
/*16*/      private L7_Obj o;
/*17*/      WorkerDemo1(L7_Obj y) { o = y; }
/*18*/      public void run() {
/*19*/          o.inc(3);
/*20*/          System.out.println("From worker1 thread " +
                                    Thread.currentThread().getId() +
                                    " x value is " + o.getValue());
/*21*/      }
/*22*/ }

/*23*/ class L7_Obj {
/*24*/      private int value;
/*25*/      L7_Obj() { value = 0; }
/*26*/      void inc(int x) {value += x; }
/*27*/      int getValue() { return value; }
/*28*/ }

/*29*/ class WorkerDemo2 implements Runnable {
/*30*/      private L7_Obj o;
/*28*/      WorkerDemo2(L7_Obj y) { o = y; }
/*28*/      public void run() {
/*29*/          o.inc(4);
/*30*/          System.out.println("From worker2 thread " +
                                    Thread.currentThread().getId() +
                                    " x value is " + o.getValue());
/*31*/      }
/*32*/ }
