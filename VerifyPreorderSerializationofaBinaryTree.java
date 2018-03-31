class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] strArray = preorder.split(",");
        Stack<String> nodeStack = new Stack<String>();
        int size = strArray.length;
        
        if(size == 0){
            return false;
        } else if(size == 1 && strArray[0].equals("#")){
            return true;
        }
        
        nodeStack.push(strArray[0]);
        
        for(int i = 1; i != size; i ++){
            if(strArray[i].equals("#")){
                if(nodeStack.empty()){
                    return false;
                } else if(!nodeStack.peek().equals("#")){
                    nodeStack.push(strArray[i]);
                } else{
                    while(!nodeStack.empty() && nodeStack.peek().equals("#")){
                        nodeStack.pop();
                        if(nodeStack.empty()){
                            return false;
                        }
                        nodeStack.pop();
                    }
                    if(nodeStack.empty() && i == size - 1){
                        return true;
                    }
                    nodeStack.push("#");
                }
            } else{
                nodeStack.push(strArray[i]);
            }
        }
        
        return nodeStack.empty();
    }
}