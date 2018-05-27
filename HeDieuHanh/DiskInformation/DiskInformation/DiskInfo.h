//DiskInfo.h
#ifndef Disk_Info_h_
#define Disk_Info_h_

#include <vector>
//#include <list>
#include <string>
using std::vector;
using std::string;

//Cau truc LogicalPartitionInfo chua thong tin cua cac phan vung
struct LogicalPartitionInfo
{
    string rootPathName, volumeName, fileSystemName;
    unsigned long sectorsPerCluster, numberOfFreeClusters, totalNumberOfClusters;
    unsigned long volumeSerialNumber;
	long long size;
    int type;
};

//Cau truc HardiskInfo chua chua thonng tin cua o dia
struct HardiskInfo 
{
    string vendorId, productId, serialNumber;
    unsigned long bytePerSector, sectorsPerTrack, tracksPerCylinder;
    long long diskSize, cylinders;
    int driverType; 
};

// danh sach LogitcalPartitionInfo luu ket qua doc duoc tu cac phan vung
// danh sach HarddiskInfo luu ket qua doc duoc tu o dia
typedef vector<LogicalPartitionInfo *> ListLogicalPartitionInfo;
typedef vector<HardiskInfo *> ListHardiskInfo;

class DiskInfo
{
public:
	ListLogicalPartitionInfo listLogicalPartitionInfo;
    ListHardiskInfo listHardiskInfo;

	// Lay thong tin ve dang chuoi tu bo nho dem
    char* getString (const char * str, int pos, char * buf);

	//Giai phong bo nho danh sach
    void DestroyListLogicalPartitions();
    void DestroyListHardisks();

public:    
    int ReadHardisksInfo();				//doc thong tin cac o dia
    int ReadLogicalPartitionsInfo();	//doc thong tin cac phan vung
    void DestroyAll();					//giai phong bo nho sau khi dung
	ListHardiskInfo getHDisks();
	ListLogicalPartitionInfo getPartitions();
	DiskInfo();				// ham dung 
	virtual ~DiskInfo();	//ham huy
};


#endif
 
