import org.chocosolver.solver.Model;
import org.chocosolver.solver.Solution;
import org.chocosolver.solver.variables.IntVar;
import org.chocosolver.solver.constraints.extension.Tuples;
import java.util.Scanner;

public class nReine {
    public static void main(String[] args){
        Model model = new Model("nReine");
        System.out.println("Combien voulez-vous de Reines ?");
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();


        //Création des variables
        IntVar [] t = model.intVarArray("Reine",n,1,n*n);
        //on crée un tableau de n variables "Reine_i" qui prennent comme valeur une case de l'échiquier
        

        //Création des contraintes

        model.allDifferent(t).post(); //unicité des reines, pas sur une même case
        // pour interdire qu'elles soient sur la même ligne, 





    } 

/*Solution s = new Solution(model);
Solver solver = model.getSolver();
while (solver.solve()){
    s.record();
    System.out.printIn(s);
    }
*/
}
