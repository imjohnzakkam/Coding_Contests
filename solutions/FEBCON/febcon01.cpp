    #include <bits/stdc++.h>
    using namespace std;
     
    const int INFI = 1e9 +12;
     
    typedef pair<double,double> part;
     
    vector <part> coll;
     
    int n;
     
    double time ( int ind , double dis ) { return dis / (double)( coll[ind].second ); }
     
    double binary( double begin , double end , int s , int k , int e ) {
    	double x  , dis = end+begin , ma , mi; 
    	for ( int j = 0 ; j < 70; j++ ) {
    		ma = (double)INFI , mi =(double)INFI , x = (end+begin)/2;
    		for ( int i = s ; i < k ; i++ ) {
    			ma = min ( ma , time( i , x + ( coll[k-1].first - coll[i].first ) ) );
    		}
    		for ( int i = k ; i < e ; i++ ) {
    			mi = min ( mi , time ( i , ( (dis-x) + coll[i].first - coll[k].first ) * -1 ) );
    		}
    		if ( ma > mi )
    			end = x;
    		else {
    			if ( ma < mi )
    				begin = x;
    			else
    				return mi;
    		}
    	}
    	return mi;
     
    }
     
    double solve(int s , int e ) {
    	double ans = INFI;
    	while ( s < e ) {
    		int m =e , k = -1;
    		for ( int i = s+1 ; i < e ; i++ )
    			if ( coll[s].second * coll[i].second < 0 ){
    				k = i;
    				break;
    			}
    		if ( k!= -1 )
    			for ( int i = k+1 ; i < e ; i++ )
    				if ( coll[k].second * coll[i].second < 0 ) {
    					m = i;
    					break;
    				}
    		if ( k == -1 )
    			return ans;
    		ans = min ( ans , binary( 0 , coll[k].first - coll[k-1].first , s , k , m ));
    		s = m;
    	}
    	return ans;
    }
     
    int main() {
    	cin >> n;
    	for ( int i = 0 ; i < n ; i++ ) {
    		part gar;
    		int x , y;
    		scanf ( "%d" ,  &x);
    		scanf ( "%d" , &y);
    		gar.first = x ;
    		gar.second = y;
    		coll.push_back(gar);
    	}
    	sort ( coll.begin() , coll.end() );
    	double ans =INFI;
    	for ( int i = 0 ; i < n ; i++ ) {
    		if ( coll[i].second > 0 ) {
    			ans = solve(i,n);
    			break;
    		}
    	}
    	if ( ans == INFI )
    		printf ( "%.15f \n " , (double)-1 );
    	else
    		printf( "%.15f \n" , ans );
    }
