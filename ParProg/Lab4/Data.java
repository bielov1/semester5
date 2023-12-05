public class Data {

    // змінні
    public static final int N = 4;
    public static final int P = 4;
    public static final int H = N/P;

    public static int k;
    public static int e;
    public static int p;

    public static int[] X = new int[N];
    public static int[] C = new int[N];
    public static int[] R = new int[N];
    public static int[] B = new int[N];
    public static int[] G = new int[N];
    public static int[] W = new int[N];
    public static int[] Q = new int[N];
    public static int[] I = new int[N];

    public static int[][] MA = new int[N][N];
    public static int[][] MD = new int[N][N];
    public static int[][] MM = new int[N][N];
    public static int[][] MK = new int[N][N];
    public static int[][] MX = new int[N][N];
    public static int[][] MS = new int[N][N];



    // функції
    public static int[][] matricesMultiplication(int[][] mat1, int[][] mat2) {
        int MC[][] = new int[mat1.length][mat2[0].length];

        // Multiply the two matrices
        for (int i = 0; i < mat1.length; i++) {
            for (int j = 0; j < mat2[0].length; j++) {
                for (int k = 0; k < mat2.length; k++)
                    MC[i][j] += mat1[i][k] * mat2[k][j];
            }
        }

        return MC;
    }

    public static int[] vecAndMatrixMultiplication(int[] vec, int[][] mat) {
        int H[] = new int[vec.length];

        for(int i = 0; i < vec.length; i++) {
            H[i] = 0;
            for(int j = 0; j < vec.length; j++) {
                H[i] += vec[j] * mat[j][i];
            }
        }

        return H;
    }

    public static int findMax(int[] vec) {
        int max = vec[0];

        for (int i = 1; i < vec.length; i++) {
            if (vec[i] > max)
                max = vec[i];
        }

        return max;
    }

    public static int[] calculation(int pk, int[] R, int e, int[] B) {
        if (R.length != B.length) {
            throw new IllegalArgumentException("Vectors R and B must be of the same length.");
        }

        int[] result = new int[R.length];

        for (int i = 0; i < R.length; i++) {
            result[i] = pk * R[i] + e * B[i];
        }

        return result;
    }

    public static void printX() {
        System.out.print("X = {");
        for(int i = 0; i < N-1; i++) {
            System.out.print(X[i] + ", ");
        }
        System.out.println(X[N-1] + "}");
    }
}
