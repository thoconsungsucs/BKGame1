#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>  // Bao gồm thư viện này
#include <iomanip>
#include"struct.cpp"
using namespace std;

class Object {
private:
    string path, name;
    string posX, posY, posZ;
    string scaleX, scaleY, scaleZ;
    string rotX, rotY, rotZ;

public:
    Object() {
        path = "";
        name = "";
        posX = "0"; posY = "0"; posZ = "0";
        scaleX = "1"; scaleY = "1"; scaleZ = "1";
        rotX = "0"; rotY = "0"; rotZ = "0";
    }

    Object(string path, string name, string posX, string posY, string posZ,
           string scaleX, string scaleY, string scaleZ,
           string rotX, string rotY, string rotZ)
            : path(path), name(name), posX(posX), posY(posY), posZ(posZ),
              scaleX(scaleX), scaleY(scaleY), scaleZ(scaleZ),
              rotX(rotX), rotY(rotY), rotZ(rotZ) {
        // Constructor đã sử dụng initializer list để gán giá trị
    }

    // Các phương thức getter
    string getName() { return name; }

    string getPosX() { return posX; }

    string getPosY() { return posY; }

    string getPosZ() { return posZ; }

    string getScaleX() { return scaleX; }

    string getScaleY() { return scaleY; }

    string getScaleZ() { return scaleZ; }

    string getRotX() { return rotX; }

    string getRotY() { return rotY; }

    string getRotZ() { return rotZ; }

    // Các phương thức setter
    void setName(string n) { name = n; }

    void setPosX(string x) { posX = x; }

    void setPosY(string y) { posY = y; }

    void setPosZ(string z) { posZ = z; }

    void setScaleX(string x) { scaleX = x; }

    void setScaleY(string y) { scaleY = y; }

    void setScaleZ(string z) { scaleZ = z; }

    void setRotX(string x) { rotX = x; }

    void setRotY(string y) { rotY = y; }

    void setRotZ(string z) { rotZ = z; }
};


class Map {
private:
    string name;
    vector<Object> objList;
    string matrix[10][10] = {{"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                             {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"}};
public:
    Map(string index) {
        name = index;
    }

    string getIndex() {
        return name;
    };

    const string (*getMatrix() const )[10] {
        return matrix;
    }

    vector<Object> getList() {
        return objList;
    }

    void setName(string n) {name = n;};

    void setObjList(vector<Object> list) {
        objList = list;
    }

    void setMatrix() {
        for (int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++)
            {
                matrix[i][j] = "0";
            }
        }
        for (int i = 0; i < objList.size(); i++) {
            int x = stoi(objList[i].getPosX());
            int y = stoi(objList[i].getPosY());

            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                matrix[x][y] = objList[i].getName();
            } else {
                cout << "Invalid coordinates for object: " << objList[i].getName() << endl;
            }
        }
    }

    string getElementAt(int x, int y) {
        return matrix[x][y];
    }




    void printMatrix() {
        cout << "Map " << name << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (matrix[i][j] == "0") {
                    cout << setw(6) << matrix[i][j][0] << matrix[i][j][matrix[i][j].size() - 1];
                } else {
                    // Print the content with brackets and ensure it's padded to width 5
                    cout << setw(4) << "[" << matrix[i][j][0]  << matrix[i][j][matrix[i][j].size() - 1] << "]";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    int objtotal(int &opt){

        int count = 0;
        if(opt == 1){
            for (int i = 0; i < objList.size(); i++)
            {
                if (objList[i].getName().substr(0,4) == "TREE")
                    count++;
            }
        }
        else if (opt == 2){
            for (int i = 0; i < objList.size(); i++)
            {
                if (objList[i].getName().substr(0,5) == "HOUSE")
                    count++;
            }
        }
        else if(opt == 3) {
            for (int i = 0; i < objList.size(); i++)
            {
                if (objList[i].getName().substr(0,4) == "CAR")
                    count++;
            }
        }
        return count;
    }

    void addObject(Object obj) {
        objList.push_back(obj);
        setMatrix();
    }

    void printallObjects() {
        cout << "Objects in Map " << name << ":" << endl;
        for (int i = 0; i < objList.size(); i++) {
            cout << "  Object " << i + 1 << ":" << endl;
            cout << "  Name: " << objList[i].getName() << endl;
            cout << "  Position: (" << objList[i].getPosX() << ", " << objList[i].getPosY() << ", " << objList[i].getPosZ() << ")" << endl;
            cout << "  Scale: (" << objList[i].getScaleX() << ", " << objList[i].getScaleY() << ", " << objList[i].getScaleZ() << ")" << endl;
            cout << "  Rotation: (" << objList[i].getRotX() << ", " << objList[i].getRotY() << ", " << objList[i].getRotZ() << ")" << endl;
            cout << endl;
        }
    }

    void printanObject(int index)
    {
        cout << "  Name: " << objList[index].getName() << endl;
        cout << "  Position: (" << objList[index].getPosX() << ", " << objList[index].getPosY() << ", " << objList[index].getPosZ() << ")" << endl;
        cout << "  Scale: (" << objList[index].getScaleX() << ", " << objList[index].getScaleY() << ", " << objList[index].getScaleZ() << ")" << endl;
        cout << "  Rotation: (" << objList[index].getRotX() << ", " << objList[index].getRotY() << ", " << objList[index].getRotZ() << ")" << endl;
    }

    int totalobj(){
        return objList.size();
    }
};


vector<Map> mapList;

bool readFile(const string &filename) {
    string line, nameMap, objID, objName, modelName;
    string posX, posY, posZ, scaleX, scaleY, scaleZ, rotX, rotY, rotZ;
    fstream input;
    input.open(filename, ios::in);

    if (!input.is_open()) {
        cout << "FILE ERROR. Cannot open file: " << filename << ". Please try again!\n";
        return false;
    }

    Map curMap(""); // Tạo một bản đồ tạm
    vector<Object> curObjList;
    while (getline(input, line)) {
        if (line.empty()) { // Khi gặp một dòng trống(chuyển sang map khác)
            if (!curMap.getIndex().empty()) { // Kiểm tra xem có bản đồ hiện tại không
                curMap.setObjList(curObjList);
                curMap.setMatrix();
                mapList.push_back(curMap); // Lưu bản đồ hiện tại vào danh sách
                curMap = Map(""); // Reset bản đồ hiện tại
                curObjList.clear();
            }
            continue;
        }

        if (line[0] == 'M') { // Đây là tên bản đồ
            nameMap = line.substr(3); // tên bản đồ bắt đầu sau 3 ký tự đầu
            curMap = Map(nameMap); // Tạo một bản đồ mới với tên được đọc
        } else if (line[0] == 'O' && line[1] == 'B' && line[2] == 'J') {
            // Đọc thông tin đối tượng
            objID = line;
            getline(input, objName);
            getline(input, posX, ',');
            getline(input, posY, ',');
            getline(input, posZ);
            getline(input, scaleX, ',');
            getline(input, scaleY, ',');
            getline(input, scaleZ);
            getline(input, rotX, ',');
            getline(input, rotY, ',');
            getline(input, rotZ);
            getline(input, modelName);

            // Tạo đối tượng và thêm vào danh sách đối tượng hiện tại
            Object obj(modelName, objName, posX, posY, posZ, scaleX, scaleY, scaleZ, rotX, rotY, rotZ);
            curObjList.push_back(obj); // Thêm đối tượng vào bản đồ hiện tại
        }
        // Tiếp tục đọc các dòng tiếp theo
    }

    if (!curMap.getIndex().empty()) { // Lưu bản đồ cuối cùng nếu có
        curMap.setObjList(curObjList);
        curMap.setMatrix();
        mapList.push_back(curMap);

    }

    input.close();
    return true;
}

void printMatrix(string matrix[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] == "0") {
                cout << setw(6) << matrix[i][j][0] << matrix[i][j][matrix[i][j].size() - 1];
            } else {
                // Print the content with brackets and ensure it's padded to width 5
                cout << setw(4) << "[" << matrix[i][j][0] << matrix[i][j][matrix[i][j].size() - 1] << "]";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void printMap()
{
    for (int i = 0; i < mapList.size(); i++) {
        mapList[i].printMatrix();
    }
}

//Function 1:
void play() {
    int index;
    do {
        cout << "There are " << mapList.size() << ", choose map you want to go to";
        cin >> index;
    } while (index < mapList.size() && index < 0);

    bool flag = false; // First time
    string matrix[10][10];
    int curX = 0;
    int curY = 0;
    do {
        if (index < mapList.size() || index == -1) {
            if (!flag || (curX == 9 && curY == 9)) {
                const string (*matrixPtr)[10] = mapList[index].getMatrix();
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        matrix[i][j] = matrixPtr[i][j];
                    }
                }
                matrix[0][0] = "NV";
                curX = 0;
                curY = 0;
                index++;
            }
        }
        flag = true;
        cout << "Map" << mapList[index].getIndex();
        printMatrix(matrix);
        cout << "Input W A S D to move";
        char move;
        cin >> move;
        switch (move) {
            case 'w':
                if (curX == 0 || matrix[curX - 1][curY] != "0") continue;
                matrix[curX][curY] = "0";
                matrix[curX - 1][curY] = "NV";
                curX--;
                break;
            case 'a':
                if (curY == 0 || matrix[curX][curY - 1] != "0") continue;
                matrix[curX][curY] = "0";
                matrix[curX][curY - 1] = "NV";
                curY--;
                break;
            case 's':
                if (curX == 9 || matrix[curX + 1][curY] != "0") continue;
                matrix[curX][curY] = "0";
                matrix[curX + 1][curY] = "NV";
                curX++;
                break;
            case 'd':
                if (curY == 9 || matrix[curX][curY + 1] != "0") continue;
                matrix[curX][curY] = "0";
                matrix[curX][curY + 1] = "NV";
                curY++;
                break;
            case 'e':
                flag = false;
                break;
        }
    } while (flag);
}


// Function 2: Find patch
bool isValidMove(int x, int y, const vector<vector<int>>& matrix, const vector<vector<bool>>& visited) {
    return x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] == 0 && !visited[x][y];
}

vector<Position> findPath(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Điểm xuất phát và điểm đích là cố định
    Position start = {0, 0};
    Position end = {9, 9};

    // Khởi tạo ma trận visited để theo dõi các ô đã được đi qua
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Hướng di chuyển ban đầu
    vector<Position> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Lưu trữ kết quả
    vector<Position> path;
    path.push_back(start);

    // Quy hoạch động để tìm đường đi
    Position current = start;
    while (current.x != end.x || current.y != end.y) {
        bool foundMove = false;

        for (const auto& direction : directions) {
            int new_x = current.x + direction.x;
            int new_y = current.y + direction.y;

            if (isValidMove(new_x, new_y, matrix, visited)) {
                visited[new_x][new_y] = true;
                path.push_back({new_x, new_y});
                current = {new_x, new_y};
                foundMove = true;
                break;
            }
        }

        if (!foundMove) {
            // Nếu không tìm thấy bước di chuyển hợp lệ, quay lui
            path.pop_back();
            if (!path.empty()) {
                current = path.back();
            } else {
                // Không còn đường để quay lui
                break;
            }
        }
    }

    return path;
}


//Function 3:
void createmap(){
    string name_map;
    cout << "Enter a name for a new map:";
    getline(cin,name_map);
    Map mymap(name_map);
    int index = mapList.size();
    cout << "Succesfully create a new map name:" << name_map << endl;

    char continues;
    do {
        cout << "Put object into the new map.(Y or N)";
        cin >> continues;
        continues = toupper(continues);
        if(continues == 'Y')
        {
            int option;
            cout << "1.Tree\n" << "2.House\n" << "3.Car\n";
            cout << "Enter option: ";
            cin >> option;
            int poX,poY,poZ;
            cout << "Enter position X: ";
            cin >> poX;
            cout << "Enter position Y: ";
            cin >> poY;
            cout << "Enter position Z: ";
            cin >> poZ;

            if (poX >= 0 && poX < 10 && poY >= 0 && poY < 10) {
                Object myobject;
                if (option == 1) {
                    int tree_total = mymap.objtotal(option);
                    myobject.setName("TREE" + to_string(tree_total));
                } else if (option == 2) {
                    int house_total = mymap.objtotal(option);
                    myobject.setName("HOUSE" + to_string(house_total));
                } else if (option == 3) {
                    int car_total = mymap.objtotal(option);
                    myobject.setName("CAR" + to_string(car_total));
                }

                myobject.setPosX(to_string(poX));
                myobject.setPosY(to_string(poY));
                myobject.setPosZ(to_string(poZ));
                mymap.addObject(myobject);
            }
            else {
                cout << "Invalid coordinates. Coordinates must be between 0 and 9." << endl;
            }
        }
    }while(continues == 'Y');
    mapList.push_back(mymap);
    printMap();
}


//Function 4:
bool isPositionValid(int x, int y, int z, vector<Object> &objList) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10 || z < 0 || z >= 10) return false;

    for (int i = 0; i < objList.size(); i++) {
        if (objList[i].getPosX() == to_string(x) && objList[i].getPosY() == to_string(y) && objList[i].getPosZ() == to_string(z)) {
            return false;
        }
    }
    return true;
}

void changemap() {
    int mapIndex, objectIndex, option;

    // Display available maps
    cout << "Available maps:\n";

    for (int i = 0; i < mapList.size(); i++) {
        cout << i + 1 << ". " << mapList[i].getIndex() << endl;
    }


    // Select a map
    do {
        cout << "Select a map (1 - " << mapList.size() << "): ";
        cin >> mapIndex;
    } while (mapIndex < 1 || mapIndex > mapList.size());

    // Display objects in the selected map
    mapList[mapIndex - 1].printallObjects();

    // Select an object
    do {
        cout << "Select an object (1 - " << mapList[mapIndex - 1].totalobj() << "): ";
        cin >> objectIndex;
    } while (objectIndex < 1 || objectIndex > mapList[mapIndex - 1].totalobj());

    // Display the current attributes of the selected object
    cout << "Current attributes of the selected object:\n";
    mapList[mapIndex - 1].printanObject(objectIndex - 1);

    // Choose the type of attribute to change
    cout << "Choose the type of attribute to change:\n";
    cout << "1. Change name\n";
    cout << "2. Change position\n";
    cout << "3. Change scale\n";
    cout << "4. Change rotation\n";
    cout << "Enter your choice (1 - 4): ";
    cin >> option;

    // Perform the change based on the chosen option
    switch (option) {
        case 1: // Change name
        {
            string newName;
            cout << "Enter the new name for the object: ";
            cin >> newName;
            mapList[mapIndex - 1].getList()[objectIndex - 1].setName(newName);
            break;
        }
        case 2: // Change position
        {
            vector<Object> newObjList;
            string  newX,newY,newZ;
            newObjList = mapList[mapIndex - 1].getList();

            do {
                cout << "Enter the new X position: ";
                cin >> newX;
                cout << "Enter the new Y position: ";
                cin >> newY;
                cout << "Enter the new Z position: ";
                cin >> newZ;

                if (!isPositionValid(stoi(newX),stoi(newY),stoi(newZ),newObjList)) {
                    cout << "Invalid position. Either out of bounds or position is already taken. Please try again.\n";
                } else {
                    break;
                }
            } while (true);

            newObjList[objectIndex - 1].setPosX(newX);
            newObjList[objectIndex - 1].setPosY(newY);
            newObjList[objectIndex - 1].setPosZ(newZ);
            mapList[mapIndex - 1].setObjList(newObjList);
            mapList[mapIndex - 1].setMatrix();
            break;
        }
        case 3: // Change scale
        {
            string newScaleX, newScaleY, newScaleZ;
            cout << "Enter the new X scale: ";
            cin >> newScaleX;
            cout << "Enter the new Y scale: ";
            cin >> newScaleY;
            cout << "Enter the new Z scale: ";
            cin >> newScaleZ;

            vector<Object> newObjList;
            newObjList = mapList[mapIndex - 1].getList();
            newObjList[objectIndex - 1].setScaleX(newScaleX);
            newObjList[objectIndex - 1].setScaleY(newScaleY);
            newObjList[objectIndex - 1].setScaleZ(newScaleZ);
            mapList[mapIndex - 1].setObjList(newObjList);
            break;
        }
        case 4: // Change rotation
        {
            string newRotX, newRotY, newRotZ;
            cout << "Enter the new X rotation: ";
            cin >> newRotX;
            cout << "Enter the new Y rotation: ";
            cin >> newRotY;
            cout << "Enter the new Z rotation: ";
            cin >> newRotZ;

            vector<Object> newObjList;
            newObjList = mapList[mapIndex - 1].getList();
            newObjList[objectIndex - 1].setRotX(newRotX);
            newObjList[objectIndex - 1].setRotY(newRotY);
            newObjList[objectIndex - 1].setRotZ(newRotZ);
            mapList[mapIndex - 1].setObjList(newObjList);
            break;
        }
        default:
            cout << "Invalid choice.";
            break;
    }

    // Display the updated attributes of the selected object
    cout << "Updated attributes of the selected object:\n";
    mapList[mapIndex - 1].printanObject(objectIndex - 1);
    mapList[mapIndex - 1].printMatrix();
}

//Save infor
void saveToFile(const string& filename, vector<Map>& mapList) {
    ofstream file;
    file.open("map.txt");

    if (!file.is_open()) {
        cout << "Cannot open file: " << filename << endl;
        return;
    }

    for (auto& map : mapList) {
        file << "MAP" << map.getIndex() << "\n";
        vector<Object> objList = map.getList();

        for (int i = 0; i < objList.size(); i++) {
            file << "OBJ\n";
            file << objList[i].getName() << "\n";
            file << objList[i].getPosX() << "," << objList[i].getPosY() << "," << objList[i].getPosZ() << "\n";
            file << objList[i].getScaleX() << "," << objList[i].getScaleY() << "," << objList[i].getScaleZ() << "\n";
            file << objList[i].getRotX() << "," << objList[i].getRotY() << "," << objList[i].getRotZ() << "\n";
            file << "model\\" << objList[i].getName() << ".obj" << "\n";
        }
        file << "\n";
    }

    file.close();
    cout << "Maps and objects saved to " << filename << endl;
}

int main() {
    readFile("map.txt");
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "0:Print all map.\n";
        cout << "1:Play.\n";
        cout << "2:Find path.\n";
        cout << "3:Create map.\n";
        cout << "4:Change in map.\n";
        cout << "5:Cheking for validity.\n";
        cout << "6:Exit\n";
        cout << "Enter choice:";
        cin >> choice;
        cin.ignore();
        if (choice == 0)
        {
            printMap();
        }

        else if (choice == 1)
        {
            play();
        }

        else if (choice == 2)
        {
            mapList[0].getElementAt(0,0);

            // Khởi tạo vector
            vector<vector<int>> inputMatrix3;
            // Hỏi người dùng muốn bắt đầu từ Map nào
            // int mapfirstIndex;
            // cout <<"Please enter your start map you want to find path: ";
            // cin >> mapfirstIndex;
            // // cout <<"Please enter your last map you want to finish : ";
            // cout <<endl;
            for (int i = 0; i< 10;i++){
                vector<int> row;
                for(int j =0; j< 10; j++){
                    if (mapList[0].getElementAt(i,j)=="0"){
                        row.push_back(0);
                    }
                    else{
                        row.push_back(1);
                    }
                }
                inputMatrix3.push_back(row);
            }
            // In dữ liệu của inputMatrix3 để kiểm tra
            for (const auto& row : inputMatrix3) {
                for (int value : row) {
                    cout << value << " ";
                }
                    cout << endl;
            }
                vector<Position> path = findPath(inputMatrix3);

                // In đường đi
                for (int i = 0; i < path.size(); i++) {
                    cout << "(" << path[i].x << ", " << path[i].y << ") ";
                }

        }
        
        else if (choice == 3)
        {
            createmap();
        }

        else if (choice == 4)
        {
            changemap();
        }

        else if (choice == 5)
        {

        }

        else if (choice == 6)
        {
            cout << "ENDING PROGRAM!" << endl;
            saveToFile("map.txt",mapList);
            break;
        }
    }
}