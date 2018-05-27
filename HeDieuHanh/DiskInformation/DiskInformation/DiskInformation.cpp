

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <list>
#include "DiskInfo.h"
using namespace std;
static DiskInfo diskInfo;

void display(HardiskInfo item ) {
	
	cout << " Nha san xuat:		  " <<item.vendorId<<endl;
	cout << " Ma SP:			  " <<item.productId<<endl;
	cout << " So hieu SP:		  " <<item.serialNumber<<endl;
	cout << " So byte/Sector:	  " <<item.bytePerSector<<endl;
	cout << " So sectors/Track:	  " <<item.sectorsPerTrack<<endl;
	cout << " So tracks/Cylinder: " <<item.tracksPerCylinder<<endl;
	cout << " Kich thuoc o dia (KB):" << item.diskSize<<endl;
	cout << " So cylinders:		  " <<item.cylinders <<endl;
	cout << " driverType: 		  " << item.driverType<<endl;
}

void display(LogicalPartitionInfo item ) {
	
	cout << " rootPathName:		  " <<item.rootPathName<<endl;
	cout << " volumeName:			  " <<item.volumeName<<endl;
	cout << " fileSystemName:		  " <<item.fileSystemName<<endl;
	cout << " sectorsPerCluster:	  " <<item.sectorsPerCluster<<endl;
	cout << " numberOfFreeClusters:	  " <<item.numberOfFreeClusters<<endl;
	cout << " totalNumberOfClusters: " <<item.totalNumberOfClusters<<endl;
	cout << " volumeSerialNumber:	" << item.volumeSerialNumber<<endl;
	cout << " size (KB):		  " <<item.size <<endl<<endl;
	//cout << " driverType: 		  " << item.driverType<<endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"\n Cac thong so o cung: "<<endl;
	diskInfo.ReadHardisksInfo();
	ListHardiskInfo listDisk = diskInfo.getHDisks();
	display(*listDisk.front());
	
	cout<<"\n\n Cac thong so cac phan vung: "<<endl;
	diskInfo.ReadLogicalPartitionsInfo();
	ListLogicalPartitionInfo listPart = diskInfo.getPartitions();
	display(*listPart.front());
	int index=0;
	while( !listPart.empty()){
		index++;
		display(*listPart[index]);
	}
	getch();
	return 0;
}
