/*
Design a ride sharing application
 */

public Cab{//Used by cab driver through mobile/web  root is fixed for all from/to pair
			//halting stops are also fixed

	private int vehicleNo;
	private String from;
	private String to;
	private String currentLocation;//milliseconds
	private boolean sharable;//Sharable or not
	//send the above info to uber onetime
	public boolean sendInfoToUberRestService(){
	//This method updates data for the ConcurrentHashMap i.e. locationCabs, in class
	//SharedCabscatalog
	}
	public boolean sendCurrentLocation(){//every 2 minute/configurable
	}
	public void refreshData(){//called after every trip
	}
	public boolean book(int time, String from, String to){
	//if sharable, still seat available and yet has not reached from then book it
	}
}

public SharedCabscatalog{//Updated every 2 minutes
	//seperate java process for every city
	//For each location all vehicle numbers which are on the way to reach this location
	//The location may not be the destination. It may be in the mid way
	private ConcurrentHashMap<String,ArrayList<Integer>> locationCabs;

	public int[]  cabAvailability(String from, String to, int time){
		//check locationCabs and see if from and to contains same vehiclenumber
		//return that
	}

	public boolean update(String from, String to, int vehicleNumber){
	//used by the webservice call from the cab
	}
public boolean book(String from, String to, int vNo){
//call webservice to book the cab
}

}
