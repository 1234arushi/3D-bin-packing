#include<bits/stdc++.h>
using namespace std;


class Company
{
public:
  int bincount = 1;
  float sum;
    vector < float >length;
    vector < float >height;
    vector < float >width;
    
  void menu ();
  void getInput (vector < float >&length, vector < float >&height,
		 vector < float >&width);
  void binprofit ();
  void Cluster ();
  void numbins ();
  void Process (int n, vector < float >&height, vector < float >&length,
		vector < float >&width);
};

void
Company::menu ()		//TO SHOW MENU
{
  cout << endl <<
    "                                                                         MENU:)";

  cout << endl <<
    "__________________________________________________________"
    << endl;

  cout << endl << "1.Add new box          " << endl
    << "2.Clusters   " << endl
    << "3.No of Bins required  " << endl
    << "4.Bin Profit           " << endl << "5.Exit                 " << endl;
  cout << "__";
}

void
Company::Process (int n, vector < float >&height, vector < float >&length,
		  vector < float >&width)
{
  int i;
  int key = 0;
  int j, x = 0;
  float a, b;
  float heightsort[n];
  for (i = 0; i < n; i++)
    {
      heightsort[i] = height[i];
    }

  float basearea[n];
  for (i = 0; i < n; i++)
    {
      basearea[i] = length[i] * width[i];
    }

  float temp3, temp4;

  for (i = 0; i < (n - 1); i++)
    {
      for (j = 0; j < n - i - 1; j++)
	{
	  if (heightsort[j] < heightsort[j + 1])
	    {
	      temp3 = heightsort[j];
	      heightsort[j] = heightsort[j + 1];
	      heightsort[j + 1] = temp3;
	      temp4 = basearea[j];
	      basearea[j] = basearea[j + 1];
	      basearea[j + 1] = temp4;
	    }
	}
    }

  cout << "\n\n\nBase Area Of Each Box : \n";

  for (i = 0; i < n; i++)
    {
      cout << basearea[i] << endl;
    }

  float cluster[n][n];
  float clusterarea[n][n];

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  cluster[i][j] = 0;
	  clusterarea[i][j] = 0;
	}
    }

  int sm = 0;
  int num_cluster = 0;
  for (i = 0; i < n; i++)
    {
      a = heightsort[key];	// a = max heigth
      for (j = key; j < n; j++)
	{
	  if (heightsort[j] >= (0.75 * a))
	    {
	      cluster[i][j - x] = heightsort[j];
	      clusterarea[i][j - x] = basearea[sm];
	      sm++;

	    }
	  else
	    {
	      x = j;
	      key = j;
	      break;
	    }
	  if (j == (n - 1))
	    {
	      i = n - 1;
	    }

	}
    }


  cout <<
    "\n\n\nCluster Containing Height Elements Of Same Height or Greater 0.75*Layer Height.\n";
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  cout << cluster[i][j] << "\t";
	}
      cout << endl;
    }

  cout << "\n\n\nCluster Wise Area Initial\n";
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  cout << clusterarea[i][j] << "\t";
	}
      cout << endl;
    }
  int k;
  for (i = 0; i < n; ++i)
    {
      for (j = 0; j < n; ++j)
	{
	  for (k = (j + 1); k < n; ++k)
	    {
	      if (clusterarea[i][j] < clusterarea[i][k])
		{
		  a = clusterarea[i][j];
		  clusterarea[i][j] = clusterarea[i][k];
		  clusterarea[i][k] = a;
		}
	    }
	}
    }
  cout << "\n\n\nCluster Wise Base Area Sorted : \n";
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  cout << clusterarea[i][j] << "\t";
	}
      cout << endl;
    }


  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	{
	  if (clusterarea[i][j] > 0)
	    {
	      sum = sum + clusterarea[i][j];
	      if (sum > 27.6)
		{
		  sum = sum - clusterarea[i][j];
		  cout << "No Further Boxes Can Be Loaded in Bins " <<
		    bincount << endl;
		  cout << "Total Base Area Covered of Bins " << bincount <<
		    " is : " << sum << endl;
		  sum = clusterarea[i][j];
		  bincount++;
		}
	    }
	}
    }
  cout << "\nTotal Base Area Covered of Bins " << bincount << " is : " << sum;
  cout << "\n\n\t\t\tThe Total Number Of Bins Needed For Transportation is : "
    << bincount;
}

void
Company::getInput (vector < float >&length, vector < float >&height,
		   vector < float >&width)
{
  float z;
  int n, i;
  int key = 0;
  int j, x = 0;
  float a, b;

  cout << "Maximum Permissible Dimension Are As Follows: \n\t WIDTH - 2.3m. \n\t Length - 12m \n\t HEIGHT - 3m.\n\n";	//these are the dimensions of single bin
  cout << "Please Enter the number of Boxes to be Transported : ";
  cin >> n;

  for (i = 0; i < n; i++)
    {

      cout << endl;
      cout << "Enter the Width in meter of Box No : " << i + 1 << endl;
      cin >> z;
      width.push_back (z);

      if (width[i] > 2.3 || width[i] < 0)
	{

	  cout << "Entered value was not incorrect. " << endl;
	  cout << "Please Re-Enter the Width in meter of Box No : " << i + 1;
	  cin >> width[i];
	}


      cout << endl << "Enter the length in meter of Box No : " << i +
	1 << endl;
      cin >> z;
      length.push_back (z);
      if (length[i] > 12 || length[i] < 0)
	{
	  cout << "Entered value was not incorrect. " << endl;
	  cout << "Please Re-Enter the Length in meter of Box No : " << i + 1;
	  cin >> length[i];
	}


      cout << endl << "Enter the Height in meter of Box No : " << i +
	1 << endl;
      cin >> z;
      height.push_back (z);

      if (height[i] > 3 || height[i] < 0)
	{
	  cout << "Entered value was not incorrect. " << endl;
	  cout << "Please Re-Enter the Height in meter of Box No : " << i +
	    1 << endl;
	  cin >> height[i];
	}

      cout << "\n\t\t\t\t\tDimensions Of The Box Have Been Stored.\n";

    }

}

void
Company::numbins ()
{
  cout << "\n\n\t\t\tThe Total Number Of Bins Needed For Transportation is : "
    << bincount;
}

void
Company::binprofit ()
{
  int profit = 10 * bincount;
  cout << "\n\n\t\t\tThe Total Profit For Transportation Per Bin is: $" <<
    profit << endl;
  cout << "($10 per bin)" << endl;
}

void
Company::Cluster ()
{
  Process (height.size (), height, length, width);
}

int main ()
{
  Company c;
  int choice;
  system ("Color 02");
  system ("cls");

  do
    {

      cout << endl;
      cout <<
	"                                                                       PACKERS AND MOVERS"
	<< endl;
      c.menu ();
      cout << endl << endl << "ENTER YOUR CHOICE : ";
      cin >> choice;
      system ("cls");
      switch (choice)
	{
	case 1:
	  c.getInput (c.length, c.height, c.width);
	  break;

	case 2:
	  c.Cluster ();
	  break;

	case 3:
	  c.numbins ();
	  break;

	case 4:
	  c.binprofit ();
	  break;

	case 5:
	  exit (0);
	  return 0;

	default:
	  cout << "Invalid Choice" << endl;
	}

    }
  while (choice != 5);

  return 0;
}
