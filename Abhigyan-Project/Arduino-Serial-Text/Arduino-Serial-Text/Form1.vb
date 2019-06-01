Public Class Form1

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        SerialPort1.Write(TextBox1.Text)
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            SerialPort1.Open()
        Catch ex As Exception
            MsgBox("Please Connect Arduino First...")
            Me.Close()
        End Try
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        SerialPort1.Write("red+")
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        SerialPort1.Write("red-")
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        SerialPort1.Write("green+")
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        SerialPort1.Write("green-")
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        SerialPort1.Write("blue+")
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        SerialPort1.Write("blue-")
    End Sub

    Private Sub BunifuFlatButton1_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton1.Click
        SerialPort1.Write("off")
        BunifuSwitch1.Value = False
        BunifuSwitch2.Value = False
        BunifuSwitch3.Value = False
        BunifuSwitch4.Value = False
    End Sub

    Private Sub BunifuFlatButton2_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton2.Click
        SerialPort1.Write("redonly")
    End Sub

    Private Sub BunifuFlatButton3_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton3.Click
        SerialPort1.Write("greenonly")
    End Sub

    Private Sub BunifuFlatButton4_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton4.Click
        SerialPort1.Write("blueonly")
    End Sub

    Private Sub BunifuFlatButton5_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton5.Click
        SerialPort1.Write("redgreen")
    End Sub

    Private Sub BunifuFlatButton6_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton6.Click
        SerialPort1.Write("greenblue")
    End Sub

    Private Sub BunifuFlatButton7_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton7.Click
        SerialPort1.Write("redblue")
    End Sub

    Private Sub BunifuFlatButton8_Click(sender As Object, e As EventArgs) Handles BunifuFlatButton8.Click
        SerialPort1.Write("white")
    End Sub

    Private Sub BunifuSwitch1_Click(sender As Object, e As EventArgs) Handles BunifuSwitch1.Click
        SerialPort1.Write("r1toggle")
    End Sub

    Private Sub BunifuSwitch2_Click(sender As Object, e As EventArgs) Handles BunifuSwitch2.Click
        SerialPort1.Write("r2toggle")
    End Sub

    Private Sub BunifuSwitch3_Click(sender As Object, e As EventArgs) Handles BunifuSwitch3.Click
        SerialPort1.Write("r3toggle")
    End Sub

    Private Sub BunifuSwitch4_Click(sender As Object, e As EventArgs) Handles BunifuSwitch4.Click
        SerialPort1.Write("r4toggle")
    End Sub
End Class
