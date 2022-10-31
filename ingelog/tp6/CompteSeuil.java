public class CompteSeuil extends Compte{

    private int seuil;
    private int compteur;

    public CompteAvecSeuil(int s){
        seuil = s;
        compteur = 0;
    }

    @Override
    public float prixLoc(Produit p){
        return p;
    }
}
