#ifndef DEF_SERVO
#define DEF_SERVO
#include <chrono>
#include <thread>
#include <math.h>
#include <cmath>
#include <wiringPi.h>
#include <iostream>
#include <fstream>
/**
 * @file libServo.h
 * @author Gergerly Pogany
 * @section DESCRIPTION
 * The Servo class provides all the functions used to control the motor
*/
/**
 * @brief Provides all functions required for motor control
*/
class Servo
{

  public:
 /**
  * @brief Constructor that sets up Servo pin and reads calibration file to set correct values
  * @param Takes in pin Servo motor is located on
  */
    Servo(int pin);
 /**
 * @brief Initialises servo pin to center postition
 */
    void init();
 /**
 * @brief Sets servo motor to an angle and leaves it there for a brief period to allow bottles to exit tube
 * @param degree Angle servo is being moved to
 */
    void move(float degree);
  /**
   * @brief Moves servo without any pause to allow real time calibration
   * @param degree degree the servo is to be moved to
   */
    void moveCalib(float degree);
  /**
   * @brief Moves servo to position required for brown glass
   */
    void moveBrown();
  /**
   * @brief Moves servo to clear glass position
   */
    void moveClear();
  /**
   * @brief Moves servo to central position (also clear glass position)
   *  without any delay
  */
    void moveClearCalib();
   /**
    * @brief Moves servo motor to green glass position
    */
    void moveGreen();
    /**
     * @brief Sets amount of time motor waits for bottle to leave the pipe
     * @param Htime Amount of time for servo to pause in milliseconds
     */
    void setHaltTime(int Htime);
    /**
     * @brief Sets angle between rest position and the brown and green glass positions
     * @param SepAngle Angle in degrees between restposition and moved position for detected glass
     */
    void setSepAngle(float SepAngle);
    /**
     * @brief gets rest position
     */
    int getRestPosition();
    int getHaltTime();
    int getSepAngle();
    /**
     * @brief Saves all set calibration values to a readable text file
     */
    void saveCalibValues();
    /**
     * @brief Sets rest position for motor
     * @param clearAngle sets central angle which is also angle for clear glass
     */
    void setRestPosition(float clearAngle);

  private:
    int m_pin; //!< Pin servo motor signal is sent to
    float m_greenAngle; //!< Angle which the servo motor goes to when green glass is detected
    float m_brownAngle; //!< Angle which the servo motor goes to when brown glass is detected
    float m_clearAngle; //!< Angle which servo is set to when clear glass is detected and where clear glass is sorted to
    float m_lastDegree; //!< The angle which the motor was last sent to
    int m_HaltTime;     //!< Time after the motor is set where it stays stationary to allow the bottle to exit the tube
    float m_SepAngle;   //!< Angle away from the rest postion that the motor moves by in each direction to sort green and brown glass
    int pwmClock;
    int pwmRange;
};

#endif
