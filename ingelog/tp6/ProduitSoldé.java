public class ProduitSoldÃ© extends Produit{
    
    public ProduitSoldÃ©(float p, String n){
        super (p,n);
    }

    @Override
    public float prixLoc(){
        return p;
    }
}
