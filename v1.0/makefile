CC = g++
CCFLAGS = -g 
CCLIBS = -lncurses

mygame: main.o Gui.o Game.o Item.o Player.o Tank.o RemoveItem.o Bullet.o UnmoveItem.o MedicalKit.o Laser.o EnemyTank.o NormalTank.o SuperTank.o Mine.o LaserTank.o Obstacle.o Map.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o Player.o Tank.o RemoveItem.o Bullet.o UnmoveItem.o MedicalKit.o Laser.o EnemyTank.o NormalTank.o SuperTank.o Mine.o LaserTank.o Obstacle.o Map.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -w -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o: Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

RemoveItem.o: RemoveItem.h RemoveItem.C
	$(CC) $(CCFLAGS) -c -o RemoveItem.o RemoveItem.C

UnmoveItem.o: UnmoveItem.h UnmoveItem.C
	$(CC) $(CCFLAGS) -c -o UnmoveItem.o UnmoveItem.C

MedicalKit.o: MedicalKit.h MedicalKit.C
	$(CC) $(CCFLAGS) -c -o MedicalKit.o MedicalKit.C

Laser.o: Laser.h Laser.C
	$(CC) $(CCFLAGS) -c -o Laser.o Laser.C

EnemyTank.o: EnemyTank.h EnemyTank.C
	$(CC) $(CCFLAGS) -c -o EnemyTank.o EnemyTank.C

NormalTank.o: NormalTank.h NormalTank.C
	$(CC) $(CCFLAGS) -c -o NormalTank.o NormalTank.C

SuperTank.o: SuperTank.h SuperTank.C
	$(CC) $(CCFLAGS) -c -o SuperTank.o SuperTank.C

Mine.o: Mine.h Mine.C
	$(CC) $(CCFLAGS) -c -o Mine.o Mine.C

LaserTank.o: LaserTank.h LaserTank.C
	$(CC) $(CCFLAGS) -c -o LaserTank.o LaserTank.C

Obstacle.o: Obstacle.h Obstacle.C
	$(CC) $(CCFLAGS) -c -o Obstacle.o Obstacle.C

Map.o: Map.h Map.C
	$(CC) $(CCFLAGS) -c -o Map.o Map.C
	
clean:
	rm -rf mygame *.o
