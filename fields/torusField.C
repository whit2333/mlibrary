// reads magnetic field
// fill histogram
// write out smaller map


void torusField()
{
	const int nphi = 121;
	const int ntra = 251;
	const int nlon = 251;

	// these quantities are just to check that the reading is ok
	double phiMin = 0;
	double phiMax = 30;
	double dphi = (phiMax - phiMin) / (nphi - 1);

	double rmin = 0;
	double rmax = 500;
	double dr = (rmax - rmin) / (ntra - 1);

	double zmin = 100;
	double zmax = 600;
	double dz = (zmax - zmin) / (nlon -1);

//	vector<vector<vector<int>>> bx;
//	vector<vector<vector<int>>> by;
//	vector<vector<vector<int>>> bz;
//
//	bx.resize( nphi );
//	by.resize( nphi );
//	bz.resize( nphi );
//	for(int ip=0; ip<nphi; ip++)
//	{
//		bx[ip].resize( ntra );
//		by[ip].resize( ntra );
//		bz[ip].resize( ntra );
//		for(int ir=0; ir<ntra; ir++)
//		{
//			bx[ip][ir].resize( nlon );
//			by[ip][ir].resize( nlon );
//			bz[ip][ir].resize( nlon );
//		}
//	}


	// it does not allow me to do this?
	// why?
	//	double bx[nphi][ntra][nlon];
	//	double by[nphi][ntra][nlon];
	//	double bz[nphi][ntra][nlon];

	// min, max fields in gauss
	double minB = -20000;
	double maxB =  20000;

	auto hbx = new TH1D("hbx", "hbx", 200, minB, maxB);
	auto hby = new TH1D("hby", "hby", 200, minB, maxB);
	auto hbz = new TH1D("hbz", "hbz", 200, minB, maxB);

	string fieldMap = "/opt/jlab_software/noarch/data/clas12TorusOriginalMap.dat";
	string outMap = "/opt/jlab_software/noarch/data/clas12TorusSmallMap.dat";

	string endHeader = "";
	ifstream IN(fieldMap);
	ofstream OUT(outMap);

	while(IN.good() && endHeader != "</mfield>") {
		IN >> endHeader;
	}

	double iphi, iz, ir;
	double tbx, tby, tbz;

	int sbx, sby, sbz;

	int everyPhi    = 1;
	int everyPhiMax = 8;

	for(int p=0; p<nphi; p++) {
		for(int r=0; r<ntra; r++) {
			for(int z=0; z<nlon; z++) {

				// these are kilogauss
				IN >> iphi >> ir >> iz >> tbx >> tby >> tbz;

				if(iphi != phiMin + dphi*p) {
					cout << " phi mismatch for index " << p << "  iphi:"  << iphi << "  wanted: " << phiMin + dphi*p << endl;
				}
				if(ir != rmin + dr*r) {
					cout << " r mismatch for index " << r << "  ir:"  << ir << "  wanted: " << rmin + dr*r << endl;
				}
				if(iz != zmin + dz*z) {
					cout << " z mismatch for index " << z << "  iz:"  << iz << "  wanted: " << zmin + dz*z << endl;
				}

				// entering as gauss
				//bx[iphi][iz][ir] = 12;
//				hbx->Fill(tbx*1000);
//				hby->Fill(tby*1000);
//				hbz->Fill(tbz*1000);

				// adding 0.5 so round up is correct
				sbx = (int) (tbx*1000 + 0.5);
				sby = (int) (tby*1000 + 0.5);
				sbz = (int) (tbz*1000 + 0.5);

				if(everyPhi == 1) {
					OUT << iphi << "\t" << ir << "\t" << iz << "\t" << sbx << "\t" << sby << "\t" << sbz << endl;
				}

				if(everyPhi == everyPhiMax) everyPhi = 1;


			}
		}
		cout << iphi << endl;
		if(everyPhi == 1) {
			cout << "tag " << iphi << endl;
		}
		everyPhi++;


	}


	hbx->Draw();



}
