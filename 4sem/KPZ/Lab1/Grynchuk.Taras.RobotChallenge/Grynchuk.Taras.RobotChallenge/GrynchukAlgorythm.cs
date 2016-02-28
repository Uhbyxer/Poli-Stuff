using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Robot.Common;

namespace Grynchuk.Taras.RobotChallenge
{
    public class GrynchukAlgorythm : IRobotAlgorithm

    {
        public Position FindNearestFreeStation(Robot.Common.Robot movingRobot, Map map, IList<Robot.Common.Robot> robots)
        {
            EnergyStation nearest = null;
            int minDistance = int.MaxValue;
            foreach (var station in map.Stations)
            {
                if (IsStationFree(station, movingRobot, robots))
                {
                    int d = DistanceHelper.FindDistance(station.Position, movingRobot.Position);

                    if (d < minDistance)
                    {
                        minDistance = d;
                        nearest = station;
                    }
                }
            }

            return nearest == null ? null : nearest.Position;
        }

        public bool IsStationFree(EnergyStation station, Robot.Common.Robot movingRobot, IList<Robot.Common.Robot> robots)
        {
            return IsCellFree(station.Position, movingRobot, robots);
        }

        public bool IsCellFree(Position cell, Robot.Common.Robot movingRobot, IList<Robot.Common.Robot> robots)
        {
            foreach (var robot in robots)
            {
                if (robot != movingRobot)
                {
                    if (robot.Position == cell)
                        return false;
                }
            }
            return true;
        }


        public RobotCommand DoStep(IList<Robot.Common.Robot> robots, int robotToMoveIndex, Map map)
        {
            /*
            if ((movingRobot.Energy > CreateNewRobotCommand.MinEnergyToCreateNewRobot) && (robots.Count < map.Stations.Count))
            {
                return new CreateNewRobotCommand();
            }
             */


            Robot.Common.Robot movingRobot = robots[robotToMoveIndex];
            Position stationPosition = FindNearestFreeStation(robots[robotToMoveIndex], map, robots);

            if (stationPosition == null)
                return null;

            if (stationPosition == movingRobot.Position)
                return new CollectEnergyCommand();
            else
            {
                Position newPosition = stationPosition;
                int distance = DistanceHelper.FindDistance(stationPosition, movingRobot.Position);
                if (distance > 20)
                {

                    int dx = Math.Sign(stationPosition.X - movingRobot.Position.X) * Math.Min(Math.Abs(stationPosition.X - movingRobot.Position.X), 5);
                    int dy = Math.Sign(stationPosition.Y - movingRobot.Position.Y) * Math.Min(Math.Abs(stationPosition.Y - movingRobot.Position.Y), 5);
                    newPosition = new Position(movingRobot.Position.X + dx, movingRobot.Position.Y + dy);
                }
                return new MoveCommand() { NewPosition = newPosition };
            }
        }

        public string Author {
            get { return "Grynchuk Taras"; } 
        }
        public string Description {
            get { return "This is my simple algorithm to move the robot."; }
        }
    }
}
