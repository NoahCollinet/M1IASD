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
        IntVar [] t = model.intVarArray("ReineColonne",n,0,n-1);
        model.allDifferent(t).post();

        //Création des contraintes







    } 

/*Solution s = new Solution(model);
Solver solver = model.getSolver();
while (solver.solve()){
    s.record();
    System.out.printIn(s);
    }
*/
}
