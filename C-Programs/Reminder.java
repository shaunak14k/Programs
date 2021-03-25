import java.util.Timer;
import java.util.TimerTask;

/**
 * Simple demo that uses java.util.Timer to schedule a task 
 * to execute once 5 seconds have passed.
 */

public class Reminder {
    Timer timer;

    public Reminder(int seconds) {
        timer = new Timer();
        timer.schedule(new RemindTask(), seconds*1000);
		System.out.println("1");
		int a=0;
		a++;
		System.out.println("VALUE : "+a);
	}

    class RemindTask extends TimerTask {
        public void run() 
		{
			int x=0;
			x++;
            System.out.println("Time's up!"+x);
            timer.cancel(); //Terminate the timer thread
        }
    }

    public static void main(String args[]) {
        new Reminder(5);
        System.out.println("Task scheduled.");
    }
}