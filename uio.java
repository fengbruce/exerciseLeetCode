public static int maxPoints(Point[] points){    
    if(points.length == 0)
        return 0;
    int max = 1;
    for(int i = 0; i < points.length - 1; i++){
        Map<Double, Integer> slope = new HashMap<Double, Integer>();
        Point p1 = points[i];
        int maxWithI = 0;
        for(int j = i + 1; j < points.length; j++){
            Point p2 = points[j];
            double d = 0;
            if(p1.x != p2.x){
                d = (double)(p2.y - p1.y)/(double)(p2.x - p1.x);
                if(d == -0.0)
                    d = 0.0;
                int count = slope.get(d) == null ? 0 : slope.get(d);
                count++;
                slope.put(d, count);
            }else if(p1.y == p2.y){
                maxWithI++;
            }else{
                d = Double.MAX_VALUE;
                int count = slope.get(d) == null ? 0 : slope.get(d);
                count++;
                slope.put(d, count);
            }

        }
        int sameSlope;
        if(slope.size() == 0){
            sameSlope = 0;
        }else{
            int maxSame = 0;
            for(Map.Entry<Double, Integer> entry : slope.entrySet()){
                if(entry.getValue() > maxSame){
                    maxSame = entry.getValue();
                }
            }
            sameSlope = maxSame;
        }
        maxWithI += sameSlope + 1;
        if(maxWithI > max){
            max = maxWithI;
        }
    }
    return max;
}
