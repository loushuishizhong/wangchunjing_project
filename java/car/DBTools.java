import java.sql.*;
import com.sun.rowset.CachedRowSetImpl;
public class DBTools
{
	public CachedRowSetImpl getResult(String sql)
	{
		try{Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		}catch(Exception e){
			System.err.println(e);
		}
		try{
			Connection conn=DriverManager.getConnection("jdbc:odbc:car","sa","123456");
			Statement stmt=conn.createStatement();
			ResultSet rs=stmt.executeQuery(sql);
			CachedRowSetImpl rowset=new  CachedRowSetImpl();
			rowset.populate(rs);
			rs.close();
			stmt.close();
			conn.close();
			return rowset;
		}catch (SQLException e){
			System.err.println(e);
		}
		return null;
	}
	public int updateResult(String sql)
	{   int a=0;
		try{//¼ÓÔØMySQLÇý¶¯
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
		}catch(Exception e){
			System.err.println(e);
		}
		try{
			
			Connection conn=DriverManager.getConnection("jdbc:odbc:car","sa","123456");
			Statement stmt=conn.createStatement();
			int num =stmt.executeUpdate(sql);
			stmt.close();
			conn.close();
			a=1;
		}catch (SQLException e){
			System.err.println(e);
		}
		return a;
	}
	  public static void main(String args[])
	  {
		  DBTools d=new DBTools();
	  }
	  
}
