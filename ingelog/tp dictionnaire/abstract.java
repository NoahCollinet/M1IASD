public abstract AbstractDictionary implements IDictionary {
    private String [] keys;
    private String [] values;
    protected int TailleTab;

    private AbstractDictionary() {
        keys = new String[];
        values = new String[];
    }
    private abstract int newIndexOf(Object key);
    private abstract int indexof(Object key);

    @Override
    private Object get(Object key){
        int i = this.indexof (key);
        return values [key];
    }
    private IDictionary put(Object key,Object value){
        int 
    }

    private boolean containskey(Object key){
        for (i=0;i<this.size();i++){
            return key.equals(this.key[i]);
        }
    }

    private int size(){
        int cpt = 0;
        int i = 0;
        while ((i<TailleTab) && (keys[i] != null))
            { i++;
              cpt++;    }
        return cpt;
        
    }

    public boolean isEmpty(){
        return size()==0;
    }
}
