import java.sql.*;
public class jdbcSample 
{
	public static void main(String args[])
	{
		Connection conn = null;
		
		try
		{
			Class.forName("com.mysql.jdbc.Driver").newInstance();
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/mydb","root","");
			
			if(!conn.isClosed())
				System.out.println("Successfully connected to MySQL Server..");
		}
		catch(Exception e)
		{
			System.err.println("Exception : "+e.getMessage());
		}
		finally
		{
			try
			{
				if(conn!=null)
					conn.close();
			}
			catch(SQLException e){}
		}
	}
}