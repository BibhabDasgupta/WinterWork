public class Main {
    public static void main(String[] args) {
        Tunnel tunnel = new Tunnel();
        tunnel.setServerAddress("t.pinggy.io:443");
        tunnel.setSniServerName("t.pinggy.io");
        tunnel.setTcpForwardTo("localhost:3000");
        tunnel.startTunnel();
        System.out.println("Tunnel started!");
    }
}
