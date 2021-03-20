import java.util.Arrays;

public class Lab_MatrixMul {
    public static void main(String[] args) {
        int[][] inputA = { { 5, 6, 7 }, { 4, 8, 9 } };
        int[][] inputB = { { 6, 4 }, { 5, 7 }, { 1, 1 } };
        MyData matA = new MyData(inputA);
        MyData matB = new MyData(inputB);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r, matC_c);
        // Q4 construct 2D array for each "thread" with respected to each cell in matC
        // Q5 start each thread
        Thread t[][] = new Thread[matC_r][matC_c];
        for (int i = 0; i < matC_r; i++) {
            for (int j = 0; j < matC_c; j++) {
                t[i][j] = new Thread(new MatrixChild(i,j,matA,matB,matC));
                t[i][j].start();
            }
        }
        //Waiting for Threads
        for (int i = 0; i < matC_r; i++) {
            for (int j = 0; j < matC_c; j++) {
                try {
                    t[i][j].join();
                } catch (Exception e) { System.out.println(e); }
            }
        }
        matC.show();
    }
}

class MatrixChild implements Runnable {
    int processing_row;
    int processing_col;
    MyData datA;
    MyData datB;
    MyData datC;
    // r*c respesent row , col of the operation and a,b,c respesent the Matrix
    MatrixChild(int ro, int co, MyData a, MyData b, MyData c) {
        // Q1 code here
        processing_row = ro;
        processing_col = co;
        datA = a;
        datB = b;
        datC = c;
    }

    /* Q2 */ public void run() {
                int x = 0;
                datC.setValue(processing_row, processing_col, 0);
                for (int i = 0; i < datA.getSize(); i++) {
                    x += datA.getData(processing_row,i) * datB.getData(i,processing_col);
                }
                datC.setValue(processing_row, processing_col, x);
        // Q3
            //System.out.println("perform multiplication of assigned row and col");
    }
}

class MyData {
    int[][] data;

    MyData(int[][] m) {
        data = m;
    }

    MyData(int r, int c) {
        data = new int[r][c];
        for (int[] aRow : data)
            Arrays.fill(aRow, 9); // 9 will be overwritten anyway
    }

    void show() {
        System.out.println(Arrays.deepToString(data));
    }

    int getData(int r, int c) {
        return data[r][c];
    }

    int getSize() {
        return data[0].length;
    }

    void setValue(int r, int c, int x) {
        data[r][c] = x;
    }
} // class