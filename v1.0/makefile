CC = g++
CCFLAGS = -g 
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Item.o Player.o Tank.o RemoveItem.o Bullet.o UnmoveItem.o MedicalKit.o Laser.o EnemyTank.o NormalTank.o SuperTank.o Mine.o LaserTank.o Obstacle.o Map.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o Player.o Tank.o RemoveItem.o Bullet.o UnmoveItem.o MedicalKit.o Laser.o EnemyTank.o NormalTank.o SuperTank.o Mine.o LaserTank.o Obstacle.o Map.o $(CCLIBS)

Gui.o: Gui.h Gui.cc
	$(CC) $(CCFLAGS) -c -w -o Gui.o Gui.cc

Game.o: Game.h Game.cc
	$(CC) $(CCFLAGS) -c -o Game.o Game.cc

main.o: main.cc
	$(CC) $(CCFLAGS) -c -o main.o main.cc

Item.o: Item.cc Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.cc

Bullet.o: Bullet.h Bullet.cc
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.cc

Player.o: Player.h Player.cc
	$(CC) $(CCFLAGS) -c -o Player.o Player.cc

Tank.o: Tank.h Tank.cc
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.cc

RemoveItem.o: RemoveItem.h RemoveItem.cc
	$(CC) $(CCFLAGS) -c -o RemoveItem.o RemoveItem.cc

UnmoveItem.o: UnmoveItem.h UnmoveItem.cc
	$(CC) $(CCFLAGS) -c -o UnmoveItem.o UnmoveItem.cc

MedicalKit.o: MedicalKit.h MedicalKit.cc
	$(CC) $(CCFLAGS) -c -o MedicalKit.o MedicalKit.cc

Laser.o: Laser.h Laser.cc
	$(CC) $(CCFLAGS) -c -o Laser.o Laser.cc

EnemyTank.o: EnemyTank.h EnemyTank.cc
	$(CC) $(CCFLAGS) -c -o EnemyTank.o EnemyTank.cc

NormalTank.o: NormalTank.h NormalTank.cc
	$(CC) $(CCFLAGS) -c -o NormalTank.o NormalTank.cc

SuperTank.o: SuperTank.h SuperTank.cc
	$(CC) $(CCFLAGS) -c -o SuperTank.o SuperTank.cc

Mine.o: Mine.h Mine.cc
	$(CC) $(CCFLAGS) -c -o Mine.o Mine.cc

LaserTank.o: LaserTank.h LaserTank.cc
	$(CC) $(CCFLAGS) -c -o LaserTank.o LaserTank.cc

Obstacle.o: Obstacle.h Obstacle.cc
	$(CC) $(CCFLAGS) -c -o Obstacle.o Obstacle.cc

Map.o: Map.h Map.cc
	$(CC) $(CCFLAGS) -c -o Map.o Map.cc
	
clean:
	rm -rf mygame *.o
