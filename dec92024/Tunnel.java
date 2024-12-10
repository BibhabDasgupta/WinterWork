public class Tunnel {
    // Load the native library (libtunnel.so)
    static {
        System.loadLibrary("pinggy");
        System.loadLibrary("tunnel");
    }

    // Native reference to the Pinggy config
    private long configRef;

    // Constructor: Calls pinggy_create_config() and stores the reference
    public Tunnel() {
        this.configRef = createConfig();
    }

    // Native method to create a Pinggy config
    private native long createConfig();

    // Native methods to set configuration values
    public native void setServerAddress(String address);
    public native void setSniServerName(String sniName);
    public native void setTcpForwardTo(String forwardTo);

    // Native method to start the tunnel
    public native void startTunnel();
}
