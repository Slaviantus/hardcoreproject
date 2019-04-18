#include "elevator.h"
#include "iostream"
#include "floor.h"


using namespace std;




void Elevator::add_floor()
{
    Floor *floor = new Floor(floors.length() + 1, scene);
    floors.push_back(floor);
    scene->addItem(floor->Getgroup());
    floors_table.resize(floors.length());
    floors_table[floors_table.length() - 1] = false;
    connect(floor, SIGNAL(doors_are_closed()), this, SLOT(control_carry_on()));
    cout << "SCENA" << scene->height() << endl;
    cout << "Floor number " << floor->Get_number() << endl;
    //======================================
//    current_floor++;
//    emit floor_Changed();


}

void Elevator::calling_the_floor()
{
    number = sender()->objectName().toInt();
    if(floors_table[number - 1] == false)
    {

    for(int i = 0; i < floors_table.size(); i++)
    {

        if(i == number - 1)
        {
            floors_table[i] = true;
        }

    }

    if((state == STOPPING) && (check_floors()))

    {
        emit carry_on();
    }

    }

}

void Elevator::floor_button_clicked(QString string)
{
    cout << "KEK" << endl;
}

void Elevator::go_up(int y)
{
    elevator_shape->setPos(342, 30 - y);


            //rightdoor->setPos(point_right_door.x() + x, 30);
}

void Elevator::Go()
{
    if(direction == UP)
    {
    timer_one_floor.setDuration(3000 * floor_difference_up);
    timer_one_floor.setFrameRange(0, 220 * floor_difference_up);
    }
    else
    {
     timer_one_floor.setDuration(3000 * floor_difference_down);
     timer_one_floor.setFrameRange(0, 220 * floor_difference_down);
    }
    timer_one_floor.start();









//    doorsTimeLine.setFrameRange(0, 30);//диапазон изменённых значений
//    doorsTimeLine.setDuration(2000);// время движения в сек
//    doorsTimeLine.setCurveShape(QTimeLine::CurveShape::EaseInOutCurve);//плавность
//    connect(&doorsTimeLine, &QTimeLine::frameChanged, this, &Floor::setDoorsPos_open);
}

void Elevator::Change_direction()
{
            state = MOVING;
            if(current_floor == floors.length())
            {
                floor_difference_up = 0;
            }
            else
            {
            for(int i = current_floor - 1; i < floors_table.size(); i++)
            {
               if(floors_table[i])
                {
                   floor_difference_up = abs(i + 1 - current_floor);
                }
            }
            }
            if(current_floor == 1)
            {
                floor_difference_down = 0;
            }
            else
            {
                for(int i = current_floor - 1; i >= 0; i--)
            {
                if(floors_table[i])
                {
                  floor_difference_down = abs(i + 1 - current_floor);
                }
             }
            }

            if((floor_difference_up == 0) && (floor_difference_down != 0))
            {
                direction = DOWN;
            }
            if((floor_difference_down == 0) && (floor_difference_up != 0))
            {
                direction = UP;
            }
            if((floor_difference_up == 0) && (floor_difference_down == 0))
            {
                state = STOPPING;
                direction = NOTHING;
            }


            if(floor_difference_up >= floor_difference_down)
            {
                direction = UP;
            }
            else
            {
                direction = DOWN;
          }
            if(direction != NOTHING || state != STOPPING)
            {
            Go();
            }

}

bool Elevator::check_floors()
{
    for(int i = 0; i < floors_table.size(); i++)
    {
        if(floors_table[i])
       {
            return true;
        }
    }
    return false;
}

void Elevator::Stopping()
{



}

void Elevator::Elevator_manager()
{
 while(check_floors())
 {
     Change_direction();
 }
}

void Elevator::Check_moving()
{
    it = floors.begin();
    if(direction == UP)
    {
        current_floor += floor_difference_up;
        it += floor_difference_up;
    }
    else
    {
        current_floor -= floor_difference_down;
        it -= floor_difference_down;
    }
    emit floor_Changed();
    (*it)->Opendoors();
    timer_stopping.start();

}

void Elevator::Closing_doors()
{
    (*it)->Closedoors();   
}

void Elevator::control_carry_on()
{
    floors_table[current_floor - 1] = false;
    if(check_floors())
       {
           emit carry_on();

       }
}

Elevator::Elevator()
{
    emit floor_Changed();

    timer_one_floor.setFrameRange(0, 220);
    timer_one_floor.setDuration(3000);

    timer_stopping.setDuration(5000);

    connect(&timer_one_floor, &QTimeLine::frameChanged, this, &Elevator::go_up);
    connect(&timer_one_floor, &QTimeLine::finished, this, &Elevator::Check_moving);
    connect(&timer_stopping, &QTimeLine::finished, this, &Elevator::Closing_doors);
    connect(this, &Elevator::carry_on, this, &Elevator::Change_direction);
   // connect(this, &Elevator::doors_are_closed, this, &Elevator::control_carry_on);


     pen.setColor(Qt::red);
     pen.setWidth(3);


     left_vertical = new QGraphicsLineItem;
     left_vertical->setPen(pen);
     left_vertical->setLine(0, 0, 0, 170);
     left_vertical->setZValue(1);
     right_vertical = new QGraphicsLineItem;
     right_vertical->setPen(pen);
     right_vertical->setLine(60, 0, 60, 170);
     right_vertical->setZValue(1);
     horizontal_up = new QGraphicsLineItem;
     horizontal_up->setPen(pen);
     horizontal_up->setLine(0, 0, 60, 0);
     horizontal_up->setZValue(1);
     horizontal_down = new QGraphicsLineItem;
     horizontal_down->setPen(pen);
     horizontal_down->setLine(0, 170, 60, 170);
     horizontal_down->setZValue(1);

     elevator_shape = new QGraphicsItemGroup;
     elevator_shape->addToGroup(left_vertical);
     elevator_shape->addToGroup(right_vertical);
     elevator_shape->addToGroup(horizontal_down);
     elevator_shape->addToGroup(horizontal_up);
     elevator_shape->setZValue(1);

     current_floor = 1;

     state = STOPPING;

 }

void Elevator::setscene(QGraphicsScene *pointer_scene)
{
    scene = pointer_scene;
    add_floor();
    add_floor();

    floors_table.resize(2);
    floors_table[0] = false;
    floors_table[1] = false;

    it = floors.begin();
    elevator_shape->setPos((*it)->Get_floor_stop_position());
    scene->addItem(elevator_shape);
//Go();
}

int Elevator::get_current_floor()
{
    return current_floor;
}


