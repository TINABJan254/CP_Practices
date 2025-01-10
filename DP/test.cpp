#include <windows.h>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct BootSector {
    uint8_t jumpInstruction[3];
    char oemName[8];
    uint16_t bytesPerSector;
    uint8_t sectorsPerCluster;
    uint16_t reservedSectors;
    uint8_t fatCount;
    uint16_t rootEntryCount;
    uint16_t totalSectors16;
    uint8_t mediaDescriptor;
    uint16_t fatSize16;
    uint16_t sectorsPerTrack;
    uint16_t headCount;
    uint32_t hiddenSectors;
    uint32_t totalSectors32;
    uint8_t driveNumber;
    uint8_t reserved;
    uint8_t bootSignature;
    uint32_t volumeID;
    char volumeLabel[11];
    char fileSystemType[8];
};

void printBootSectorInfo(const BootSector &bootSector) {
    cout << "OEM Name: " << string(bootSector.oemName, 8) << endl;
    cout << "Bytes Per Sector: " << bootSector.bytesPerSector << endl;
    cout << "Sectors Per Cluster: " << (int)bootSector.sectorsPerCluster << endl;
    cout << "Reserved Sectors: " << bootSector.reservedSectors << endl;
    cout << "FAT Count: " << (int)bootSector.fatCount << endl;
    cout << "Root Entry Count: " << bootSector.rootEntryCount << endl;
    cout << "Total Sectors (16-bit): " << bootSector.totalSectors16 << endl;
    cout << "Media Descriptor: " << hex << (int)bootSector.mediaDescriptor << dec << endl;
    cout << "FAT Size (16-bit): " << bootSector.fatSize16 << endl;
    cout << "Sectors Per Track: " << bootSector.sectorsPerTrack << endl;
    cout << "Head Count: " << bootSector.headCount << endl;
    cout << "Hidden Sectors: " << bootSector.hiddenSectors << endl;
    cout << "Total Sectors (32-bit): " << bootSector.totalSectors32 << endl;
    cout << "Volume ID: " << hex << bootSector.volumeID << dec << endl;
    cout << "Volume Label: " << string(bootSector.volumeLabel, 11) << endl;
    cout << "File System Type: " << string(bootSector.fileSystemType, 8) << endl;
}

int main() {
    // Ðu?ng d?n d?n ? dia v?t lý trên Windows (PhysicalDrive0 là ? dia d?u tiên)
    const char* drivePath = "\\\\.\\PhysicalDrive0";

    // M? ? dia v?t lý
    HANDLE hDevice = CreateFile(
        drivePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hDevice == INVALID_HANDLE_VALUE) {
        cerr << "Không th? m? thi?t b?: " << drivePath << endl;
        return 1;
    }

    // Ð?c 512 byte t? sector 0
    DWORD bytesRead;
    BootSector bootSector;
    if (!ReadFile(hDevice, &bootSector, sizeof(bootSector), &bytesRead, NULL)) {
        cerr << "L?i khi d?c boot sector" << endl;
        CloseHandle(hDevice);
        return 1;
    }

    // Ki?m tra xem chúng ta có d?c dúng 512 byte hay không
    if (bytesRead != sizeof(bootSector)) {
        cerr << "Ð?c không d? 512 byte t? boot sector" << endl;
        CloseHandle(hDevice);
        return 1;
    }

    // In thông tin boot sector
    printBootSectorInfo(bootSector);

    // Ðóng handle thi?t b?
    CloseHandle(hDevice);
    return 0;
}

