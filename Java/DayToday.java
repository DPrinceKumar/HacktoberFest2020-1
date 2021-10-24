import java.time.*;

public class DayToday {
    public static void main(String[] args) {
        LocalDate myDate = LocalDate.now(); 
        DayOfWeek day = myDate.getDayOfWeek();
        String fDay ="";
        switch (day) {
            case SUNDAY:
            fDay = "Sunday";
            break;
            case MONDAY:
            fDay = "Monday";
            break;
            case TUESDAY:
            fDay = "Tuesday";
            break;
            case WEDNESDAY:
            fDay = "Wednesday";
            break;
            case THURSDAY:
            fDay = "Thursday";
            break;
            case FRIDAY:
            fDay = "Friday";
            break;
            case SATURDAY:
            fDay = "Saturday";
            break;

        }
        
        System.out.println("Todays is " + fDay);

    }
    
}