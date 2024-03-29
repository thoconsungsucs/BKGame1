Map Game Report
Date: 8/1/2023
Prepared by: Team 3

Team Members
•	Member 1:  Nguyễn Duy Thành	
•	Member 2: Trần Văn Đức
•	Member 3: Lê Minh Hoàng

Division of work
•	Member 1:  Nguyễn Duy Thành
a.	Read File.
b.	Play function.
c.	Checking valid function.
d.	Construct class
•	Member 2: Trần Văn Đức
a.	Create and change maps.
b.	Save data.

•	Member 3: Lê Minh Hoàng
a.	Find path.
b.	Checking valid position
c.	Menu based.
1. Data Structures and Classes
Detailed description of the data structures and classes used in the project, including Position, Object, and Map classes.
2. Core Functionalities
- File I/O: readFile and saveToFile functions to load and save map and object data.
- Map Display and Manipulation: 
  - printMatrix: Displays the map layout.
  - addObject, removeObjectInMap, and changeMap: Allow users to add, remove, and modify objects in the map.
- Gameplay Mechanics: 
  - play: Function for a basic movement system in the map using 'w', 'a', 's', 'd'.
  - findPath: Finds a path from a start position to an end position.
  - createMap: Create map.
  - changeMap: Change map’s objects and attributes.
3. Error Checking and Validity
- checkValid: Checks the validity of object file paths and sizes.
- isPositionValid: Ensures that object placement does not conflict with existing objects.
4. User Interaction
A menu-driven interface allows the user to choose various operations like playing the game, creating maps, adding/removing objects, and checking validity.
5. Potential Improvements and Observations
- Error Handling: More robust error handling in file I/O operations and user inputs could enhance the program's stability.
- Gameplay Depth: The current gameplay mechanics are basic. Additional features like objectives, challenges, or interactions with map objects could enrich the experience.
- Code Organization: Breaking down the code into more files and functions could improve readability and maintainability.
- Object and Map Dynamics: Introducing more attributes or behaviors for objects and the map can make the simulation more engaging.

 
