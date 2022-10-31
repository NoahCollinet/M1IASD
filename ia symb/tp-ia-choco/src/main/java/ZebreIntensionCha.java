import org.chocosolver.solver.Model;
import org.chocosolver.solver.variables.IntVar;
// import org.chocosolver.solver.constraints.extension.Tuples;


public class ZebreIntensionCha {

	public static void main(String[] args) {
		
		// Création du modele
		Model model = new Model("Zebre");
		
		
		// Création des variables
		IntVar blu = model.intVar("Blue", 1, 5);	// blu est une variable entière dont le nom est "Blue" est le domaine [1,5]
		IntVar gre = model.intVar("Green", 1, 5); 
		IntVar ivo = model.intVar("Ivory", 1, 5);         
		IntVar red = model.intVar("Red", 1, 5);         
		IntVar yel = model.intVar("Yellow", 1, 5);   
		
		IntVar eng = model.intVar("English", 1, 5);         
		IntVar jap = model.intVar("Japanese", 1, 5);         
		IntVar nor = model.intVar("Norwegian", new int []{1});
		IntVar spa = model.intVar("Spanish", 1, 5);         
		IntVar ukr = model.intVar("Ukrainian", 1, 5);         
		
		IntVar cof = model.intVar("Coffee", 1, 5);         
		IntVar mil = model.intVar("Milk", 3);
		IntVar ora = model.intVar("Orange Juice", 1, 5);         
		IntVar tea = model.intVar("Tea", 1, 5);         
		IntVar wat = model.intVar("Water", 1, 5);         
		
	    IntVar dog = model.intVar("Dog", 1, 5);         
	    IntVar fox = model.intVar("Fox", 1, 5);         
	    IntVar hor = model.intVar("Horse", 1, 5);         
	    IntVar sna = model.intVar("Snail", 1, 5);         
	    IntVar zeb = model.intVar("Zebra", 1, 5);         
	    
	    IntVar che = model.intVar("Chesterfield", 1, 5);         
	    IntVar koo = model.intVar("Kool", 1, 5);         
	    IntVar luc = model.intVar("Lucky Strike", 1, 5);         
	    IntVar old = model.intVar("Old Gold", 1, 5);         
	    IntVar par = model.intVar("Parliament", 1, 5);         

	    
	    // Création des contraintes
	    // 1
	    IntVar[] col = new IntVar[] {blu, gre, ivo, red, yel};
	    model.allDifferent(col).post();
	    
	    IntVar[] nat = new IntVar[] {eng, spa, nor, jap, ukr};
	    model.allDifferent(nat).post();
	    
	    IntVar[] bev = new IntVar[] {cof, mil, ora, tea, wat};
	    model.allDifferent(bev).post();
	    
	    IntVar[] pet = new IntVar[] {dog, fox, hor, sna, zeb};
	    model.allDifferent(pet).post();
	    
	    IntVar[] smo = new IntVar[] {che, koo, luc, old, par};
	    model.allDifferent(smo).post();
	    
        // 2
        model.arithm(eng, "=", red).post();
        
        // 3
        model.arithm(spa, "=", dog).post();
        
        // 4
        model.arithm(cof, "=", gre).post();
        
        // 5
        model.arithm(ukr, "=", tea).post();
        
        // 6
         model.arithm(ivo, "=", gre, "-", 1).post();
                
        // 7
        model.arithm(old, "=", sna).post();
        
        // 8
        model.arithm(koo, "=", yel).post();
        
        // 9
        // Domaine de mil modifié -> 3
        
        // 10
        // Domaine de nor modifié -> 1
        
        // 11
        model.distance(che, fox, "=", 1).post();
      
        // 12
        model.distance(koo, hor, "=", 1).post();
        
        // 13
        model.arithm(luc, "=", ora).post();
        
        // 14
        model.arithm(jap, "=", par).post();
        
        // 15
        model.distance(nor, blu,"=", 1).post();
        
        
        
        // Affichage du réseau de contraintes créé
        System.out.println("*** Réseau Initial ***");
        System.out.println(model);
        

        // Calcul de la première solution
        if(model.getSolver().solve()) {
        	System.out.println("\n\n*** Première solution ***");        
        	System.out.println(model);
        }

        
/*        
    	// Calcul de toutes les solutions
    	System.out.println("\n\n*** Autres solutions ***");        
        while(model.getSolver().solve()) {    	
            System.out.println("Sol "+ model.getSolver().getSolutionCount()+"\n"+model);
	    }
*/	    
 
        
        // Affichage de l'ensemble des caractéristiques de résolution
      	System.out.println("\n\n*** Bilan ***");        
        model.getSolver().printStatistics();
	}
}
