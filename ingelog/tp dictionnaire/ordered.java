public class OrderedDictionary extends AbstractDictionary{

    private OrderedDictionary(){
        keys = this.keys[0];
        values = this.values[0]; 
    }

    private int indexof(Object key){
        int index = -1;
        for (int j=0,j<this.size();j++){
            if (key = this.key[j]){
                index = key;
            }
        }
    }

    private int newIndexOf(Object key){
        int index; 
        index = indexof(key);
        for(int i =0; i<this.size(); i++){
            
        }

    } 
}