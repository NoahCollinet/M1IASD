public class ProduitSoldé extends Produit{
    
    public ProduitSoldé(float p, String n){
        super (p,n);
    }

    @Override
    public float prixLoc(){
        return p;
    }
}
